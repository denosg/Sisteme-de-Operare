#!/bin/bash

if [ "$#" -lt 1 ]; then
	echo "Error: At least one extension required."
	echo "Tutorial: $0 extension1 [extension2 ...... extensionN]"
	exit 1
fi

for extension in "$@"; do
	echo "Deleting files with .$extension from the current directory..."
	rm -f -- *."$extension" 2>/dev/null
done


echo "Finalized..."
