#!/bin/bash

while read A B; do
    echo $(($A + $B))
done