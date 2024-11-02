#!/bin/bash

MONTH_OF_BIRTH=10
DAY_OF_BIRTH=23

# Loop through each parameter provided to the script
for arg in "$@"
do
    result=$(( (arg + MONTH_OF_BIRTH) / DAY_OF_BIRTH ))
    echo "$result"
done
