#!/bin/bash

if ! [ -n "$1" ] || ! [ -n "$2" ]
then
    echo No file or text specified
    exit 1
#elif ! [ -d $1 ]
#then
#    echo the directory doesn\'t exist
#    exit 1
else
    #myline=$( ls $1 | grep $2 | tr '\n' ' ' )
    #myvar=$( ls $1 | grep $2 | wc -l) 
    #echo "The number of files are $myvar and the number of matching lines are $myline"
    tesst=$( install -Dv /dev/null $1 )
    myfile=$( echo $2 > $1 )
    if ! [ -e $1 ]
    then
        echo "failed"
        exit 1
    fi
fi
