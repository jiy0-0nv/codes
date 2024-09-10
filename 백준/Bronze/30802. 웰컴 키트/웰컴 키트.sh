#!/bin/bash

read n
read str
sizes=(${str})
read t p

ans=0
for i in ${sizes[@]}; do
    if [ ${i} -ne 0 ]; then
        ans=$((${ans} + ((${i} - 1) / $t) + 1))
    fi
done
echo ${ans}

echo "$((n / p)) $((n - ((n / p) * p)))"