#!/bin/bash

while : ; do
    read A B
    if [ "$A" -eq 0 ] && [ "$B" -eq 0 ]; then
        break
    fi
    echo $(($A + $B))
done