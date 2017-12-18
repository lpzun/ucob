################################################################################
#  NOTE: This is a shell script for bopp preprocessor. It aims at translating # 
#  SatAbs BP to Our BP: mainly renaming labels                                #
#                                                                             #
#  INPUT  : a SatAbs Boolean program file                                     #
#  OUTPUT : a Boolen progran with out format                                  #
################################################################################
#!/bin/bash                                                                 # 
JAVA=java
JAR_FLAG=-jar
JAVA_EXE=BoPP.jar         # Java Preprocessor: SatAbs BP -> Our BP
PYTHON=python 
PYTHON_EXE=BoPP.py          # Python preprocessor

################################################################################
# The following code goes through all Boolean programs in a given directory   #
# specified by paramter [-d | --dir]; you can also specify which translator   #
# to use: the java version or the python version                              #
################################################################################
DIR=          #
IS_JAVA=0     #

while [ "$1" != "" ]; do
    case $1 in
        -d | --dir )      shift
                          DIR=$1
                          ;;
        -j | --java )     IS_JAVA=1
                          ;;
        -h | --help )     usage
                          exit
                          ;;
        * )               usage
                          exit 1
    esac
    shift
done
echo -n "Preprocessing Boolean programs in ${DIR} with "
if [ ${IS_JAVA} = 1 ]; then
	echo "${JAVA_EXE}"
    for file in $(find ${DIR} -name '*.bp' | sort); do
        $JAVA $JAR_FLAG $JAVA_EXE ${file}
    done
else
	echo "${PYTHON_EXE}"
	for file in $(find ${DIR} -name '*.bp' | sort); do
        $PYTHON $PYTHON_EXE -f ${file} -r
    done
fi 

