#!/bin/bash

for f in *
do

    for p in $1
    do

	if [ -f "$f" ]
	then
	    r='grep -c $p "$f"'
	    if [ $r -gt 0 ]
	       then
		echo "$f contient $p"

	    fi
	fi
    done
done    
