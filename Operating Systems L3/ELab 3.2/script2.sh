#!/bin/bash

# Define a variable with the names of all months
months=("January" "February" "March" "April" "May" "June" "July" "August" "September" "October" "November" "December")


BIRTH_MONTH=10

# Loop through months and display each month, skipping the birth month
for ((i = 1; i <= 12; i++)); do
    if ((i == BIRTH_MONTH)); then
        continue # Skip the birth month
    fi
    echo "$i - ${months[i-1]}"
done
