#!/bin/bash

BIRTH_DAY=23

# Initialize counter
i=1

# Loop from 1 to 32
while ((i <= 32)); do
    echo "$i"
    if ((i == BIRTH_DAY)); then
        break # Stop at birthday
    fi
    ((i++)) # Increment counter
done
