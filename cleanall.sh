#!/bin/bash

mkname="Makefile"
function listfiles(){
    for file in `ls $1`
    do
        if [ -d $1/$file ]
        then
            listfiles $1/$file
        else
            echo $1/$file
            if [ $file = $mkname ]
            then
                make -C $1 clean
                break
            fi
        fi
    done
}
listfiles .
