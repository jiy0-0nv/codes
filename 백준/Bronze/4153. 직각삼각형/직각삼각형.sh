#!/bin/bash

function right_tr {
    local a=$(($(($1 * $1)) + $(($2 * $2))))
    local c=$(($3 * $3))
    echo $(($c - $a))
}

while : ; do
    read x y z
    if [ $x -eq 0 ] && [ $y -eq 0 ] && [ $z -eq 0 ]; then
        break
    fi
    if [ $(right_tr $x $y $z) -eq 0 ]; then
        echo "right"
    elif [ $(right_tr $x $z $y) -eq 0 ]; then
        echo "right"
    elif [ $(right_tr $z $y $x) -eq 0 ]; then
        echo "right"
    else
        echo "wrong"
    fi
done