# Introduction
translating a SatAbs Boolean program format to our Boolean program format: __mainly renaming labels__.

There are two different tools with the almost the same function. 

* __BoPP.jar__ is written in Java, which is an old version used in FMCAD'14 paper and SEFM'17 paper.

* __BoPP.py__  is written in python, which is a brand new one. It can also help you remove the comment and blank lines.

So, use your favorite one. 

# Usage 

##### BoPP.jar
>     java -jar -f input-filename > output-filename

##### BoPP.py
>     BoPP.py -h

Consider to use the shell script _pproc.sh_ if you need to preprocess a bunch of Boolean programs. 

                    