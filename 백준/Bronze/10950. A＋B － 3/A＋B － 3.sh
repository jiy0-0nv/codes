#!/bin/bash

read T

for ((i=$T ; i > 0 ; i--));
do
    read A B
    echo $(($A+$B))
done