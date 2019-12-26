#!/bin/sh

#test 1 "ls -l | grep"
#test 2 "s | less || echo A"
#test 3 "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2"
#test 4 "(( [ -e header ] | tee file_name) && echo TestSuccess) || (ls -1 | cat)"
#test 5 "(( ls -1 | less) && echo TestPasses) && ( ls -1 | cat)"

INPUTS=("ls -l | grep"
        "s | less || echo A"
        "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2"
        "(( [ -e header ] | tee file_name) && echo TestSucces) || (ls -1 | cat)" 
        "(( ls -1 | less) && echo TestPasses) && ( ls -1 | cat)"
	"(( [ -e false.txt ] | s ) || echo TestPassed)"
       )
for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done


