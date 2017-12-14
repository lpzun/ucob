import os
import sys
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-f","--filename", help="input filename")
args = parser.parse_args()
with open(args.filename) as ins:
    for line in ins:
        if not line.startswith("//"):
            if line not in ['\n', '\r\n']:
                print(line.strip())

#parser = argparse.ArgumentParser()
#parser.add_argument("--verbosity", help="increase output verbosity")
#args = parser.parse_args()