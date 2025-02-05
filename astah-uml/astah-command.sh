#!/bin/sh

## Execution examples
# ---------------------------------------------------------------------------
# Shell script to run command line tool for ASTAH
# ---------------------------------------------------------------------------
# Command Examples
# ---------------------------------------------------------------------------
# sh astah-command.sh -image er -f ./Sample.asta -t png -o ./
# sh astah-command.sh -image all -f ./Sample.asta -t png -o ./
# ---------------------------------------------------------------------------
# Option Examples
# ---------------------------------------------------------------------------
# usage: Export Image Options
#  -f,--file <target file>    target file
#  -image                     export documents to image
#  -o,--output <output dir>   output dir
#  -t,--type <image type>     png/jpg/emf
# ---------------------------------------------------------------------------

#export JAVA_HOME=/usr/java/latest
#export PATH=$PATH:$JAVA_HOME/bin

#ASTAH_HOME=/usr/lib/astah_uml
ASTAH_HOME=`pwd`

INITIAL_HEAP_SIZE=64m
MAXIMUM_HEAP_SIZE=1024m
LIBPATH="$ASTAH_HOME/lib/rlm"

JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE -Djava.library.path=$LIBPATH"
#JAVA_OPTS="\$JAVA_OPTS -DrootLevel=DEBUG"

java $JAVA_OPTS -cp "$ASTAH_HOME/astah-uml.jar" com.change_vision.jude.cmdline.JudeCommandRunner "$@"
