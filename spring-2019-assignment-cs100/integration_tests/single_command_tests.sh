



#!/bin/sh



# test #1  "ls" command
# test #2  "mdkdir name" command
# test #3  "echo test" command
# test #4  "cp source destination" command
# test #6  "rm filename" command
# test #7  "rm -rf folername" command

INPUTS=("ls" "mkdir file_name" "echo test" "cp source destination" "rm filename" "rm -rf foldername")

for input in "${INPUTS[@]}"

do
	echo executing: ${input}
	./../rshell
done

