#!/bin/bash

mkname="Makefile"
function listfiles(){
    for file in `ls $1`
    do
        if [ -d $file ]
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
listfiles .
