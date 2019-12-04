#!/bin/bash

for f in *
do

    for p in $*
    do
	if grep -q $p "$f" 2> /dev/null
	then
	    echo "$f contient $p"
	fi
    done
done    
