import argparse
import os
import sys
import re

###########################################################
# commandline line
###########################################################
parser = argparse.ArgumentParser()
parser.add_argument("-f","--filename", help="input filename")
parser.add_argument("-r","--remove", 
                    help="remove comment and blank lines", 
                    action="store_true")
args = parser.parse_args()

###########################################################
# read the file line by line and: 
#  1. reformat PC labes: PC# -> #
#  2. reformat goto labels: use PC directly
###########################################################
labelMap={'l1':'1'}
label=''
bpFile = []
with open(args.filename, 'r') as ins:
    for line in ins:
        line = line.strip()
        if line.startswith('l'):
            bpFile.append("//" + line)
            label=line.rstrip(':')
        elif line.startswith('PC'):
            line = line.lstrip('PC')
            bpFile.append(line)
            # mapping the old goto lables to a numberical PC
            if label is not '':
                newLabel=line.split(':', 1)[0]
                labelMap[label]=newLabel
                label=''
        else:
            bpFile.append(line)
#print labelMap

###########################################################
# write reformatted BP to a file:
###########################################################
newBpExtension = '.nbp'
newBpName = args.filename.rsplit('.', 1)[0] + newBpExtension

with open(newBpName, 'w+') as ous:
    for line in bpFile:
        if args.remove:
            if line.startswith('//'):
                continue
            if line is '' or line in ['\n', '\r\n']:
                continue
        if "goto" in line:
            try:
                m = re.search('l[0-9]+', line)
                label = m.group(0) # indexing from 0
                # replace goto labels
                line = line.replace(label, labelMap[label])
            except AttributeError:
                label = ''
        ous.write("%s\n" % line)
print("Successfully reformat Boolean program and store it as: " + newBpName)