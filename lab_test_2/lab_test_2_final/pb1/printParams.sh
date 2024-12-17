#!/bin/bash

if [ "$#" -ne 13 ]; then
	echo "Error: At least 13 parameters required."
	exit 1
fi

echo "Entered parameters: "
for i in {1..13};do
	echo "Parameter $i: ${!i}"
done

