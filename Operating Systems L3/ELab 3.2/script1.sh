#!/bin/bash


ALBUM_NUMBER=42372

# Get the penultimate and last digits of the album number
x=${ALBUM_NUMBER: -2:1}
y=${ALBUM_NUMBER: -1:1}

# Check conditions for x and y
if (( x > y )); then
    x=$y
elif (( x == y )); then
    ((y += 2))
fi

# Display values from x to y
for ((i = x; i <= y; i++)); do
    echo "$i"
done
