#!/bin/bash

mkname="Makefile"
function listfiles(){
    for file in `ls $1`
    do
        if [ -d $1/$file ]
        then
            listfiles $1/$file
        else
            if [ $file = $mkname ]
            then
                make -C $1 clean
                break
            fi
        fi
    done
}

dir='.'
if [ $# -gt 0 ]
then
    if [ -d $1 ]
    then
        dir=$1
    else
        echo $1 not a directory
    fi
fi
listfiles $dir
