################################################################################
#  NOTE: This is a shell script for regression testing of UCOB. It goes       # 
#        through all test.bp files                                                                      #
################################################################################
#!/bin/bash                                                                   # 
EXE=../Debug/ucob

################################################################################
# The following is how to redirect  preprocessor's output to BoPP and output   # 
# the control flow grah and WP into a file                                    #
################################################################################
DIR=.
for file in $(find ${DIR} -name 'test*.bp' | sort); do
    $EXE -f ${file}
done 