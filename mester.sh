#!/bin/bash

if [ $# -lt 2 ]
then
    echo "USAGE: ./mester.sh [SOURCE].cpp [INPUT]"
    exit 1
fi

LTIME=`stat -c %Z $1`

echo "watching $1 for changes..."

while true    
do
   ATIME=`stat -c %Z $1`

   if [[ "$ATIME" != "$LTIME" ]]
   then    
       LTIME=$ATIME
       echo "file changed, compiling..."
       $(g++ -std=c++11 -O2 -g -static -lm $1 -o feladat.out)
       echo "running with input $2"
       echo "$(./feladat.out < $2)"
       echo ""
   fi
   sleep 0.5
done

