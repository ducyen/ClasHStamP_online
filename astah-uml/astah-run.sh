#!/bin/sh

## Execution examples
#astah-run.sh ASTAH_PROJECT_PATH update-all
#astah-run.sh ASTAH_PROJECT_PATH update-all use-builtin-timestamp
#astah-run.sh ASTAH_PROJECT_PATH update-all ubt
#astah-run.sh ASTAH_PROJECT_PATH update-all-force
#astah-run.sh ASTAH_PROJECT_PATH xml sample.asta sample.xml
#astah-run.sh ASTAH_PROJECT_PATH obfuscated-xml sample.asta sample.xml

#export JAVA_HOME=/usr/java/latest
#export PATH=$PATH:$JAVA_HOME/bin

#ASTAH_HOME=/usr/lib/astah_professional
ASTAH_HOME=`dirname $0`

USER_LANGUAGE=vi
INITIAL_HEAP_SIZE=64m
MAXIMUM_HEAP_SIZE=1024m

JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE"
#JAVA_OPTS="$JAVA_OPTS -DrootLevel=DEBUG"
JAVA_OPTS="$JAVA_OPTS -Duser.language=$USER_LANGUAGE"

java $JAVA_OPTS -cp "$ASTAH_HOME/astah-uml.jar" JP.co.esm.caddies.jomt.Jude "$@"
