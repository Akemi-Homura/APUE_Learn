#!/bin/bash

nreg=0
ndir=0
function listfiles(){
    for file in `ls $1`
    do
        if [ -d $1/$file ]
        then
            let ndir=ndir+1
            listfiles $1/$file
        else
            let nreg=nreg+1
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

let ntot=nreg+ndir
echo "ntot: $ntot"
echo "nreg: $nreg"
echo "ndir: $ndir"
