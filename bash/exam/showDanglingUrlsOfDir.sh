#!/bin/bash
# This script looks for all .md files in a given directory (no sub-directories) and checks
# them for links to non-existent files
# Usage: pathToScript/showDanglingUrlsOfDir.sh directory

targetDir=$1
markdownFiles=$(ls $targetDir | grep "\.md$")

echo "Dangling links in..."
for file in $markdownFiles
do
    echo "$targetDir/$file:"
    /home/nico/Desktop/exam/showDanglingUrlsOfFile.sh $targetDir/$file
    echo
done