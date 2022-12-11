#!/bin/bash
# This script detects all invalid links in a single .md file.
# Usage: somePath/showDanglingUrlsOfFile.sh someOtherPath/filename.md

filePath=$1
dirPath=$(dirname "$filePath")
linkRegex="\[.*\](.*\.[a-z0-9]*)"
fileNameFromLinkRegex="[a-z0-9\-]*\.[a-z0-9]*"

# Get the filenames of all linked files from the input file
linkedFiles=$(grep -o "$linkRegex" $filePath | grep -o "$fileNameFromLinkRegex")

# Print all the lines containing links to non-existent files
for file in $linkedFiles
do
    if [ ! -f $dirPath/$file ]
    then
        grep -n --color "$file" $filePath
    fi
done
