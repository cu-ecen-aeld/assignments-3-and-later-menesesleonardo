#!/bin/bash

if ! [ -n "$1" ] || ! [ -n "$2" ]
then
    echo No directory or filename specified
    exit 1
elif ! [ -d $1 ]
then
    echo the directory doesn\'t exist
    exit 1
else
    #myvar=$( find $1 -type f -name "*$2*" | wc -l)
    myvar=$( ls $1 | wc -l)
    myline=$( grep -R $2 $1 | wc -l ) 
    echo "The number of files are $myvar and the number of matching lines are $myline"
fi
