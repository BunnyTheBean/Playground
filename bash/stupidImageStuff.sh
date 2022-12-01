#!/bin/bash
#Call: ./stupidImageStuff inputPath outputPath desiredSize

input=$1
output=$2
desiredSize=$3

convert $input -resize 80% $output
while [[ $(ls $output -l | awk '{print $5}') -gt $desiredSize ]]
do
    echo $(ls $output -l | awk '{print $5}')
    convert $output -resize 80% $output
done