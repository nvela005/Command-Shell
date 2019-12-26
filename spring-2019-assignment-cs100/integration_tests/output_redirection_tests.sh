#!/bin/sh

#test 1 "tr a-z A-Z < test.txt > test1.txt"
#test 2 "sort < test.txt > test1.txt"
#test 3 "ls >> test.txt"
#test 4 ((( [ -e test.txt ] && (echo True A && echo \"True B with quotes\")) > test1.txt) && (echo A || echo B))"
#test 5 "ls > test.txt || echo TestFailed"


INPUTS=("tr a-z A-Z < test.txt > test1.txt"
        "sort < test.txt > test1.txt"
        "ls >> test.txt"
        "((( [ -e test.txt ] && (echo True A && echo \"True B with quotes\")) > test1.txt) && (echo A || echo B))"
        "ls > file_name || echo TestFailed"
       )
for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell

	echo ----------------
	cat < test.txt
	echo ----------------

	
	
done




#test 6 "[ test.txt ] > test.txt || echo TestFailed"
#test 7 "[ false.txt ] > test.txt || echo TestPassed"

#test 8 "[ -e test.txt ] > test.txt && echo TestPassed"
#test 9 "[-e false.txt ] > test.txt || echo TestFailed"

#test 10 "([ -f test.txt ] > test.txt)"
#test 11 "(( [ -e test.txt ] && echo A) > test.txt)"
#test 12 "(( [ -e false.txt ] || echo "True with Quotes") > test.txt)"




INPUTS=("[ test.txt ] > test.txt || echo TestFailed"
        "[ false.txt ] > test.txt || echo TestPassed"
        "[ -e test.txt ] > test.txt && echo TestPassed"
	"[ -e false.txt ] > test.txt || echo TestFailed"
	
	"([ -f test.txt ] > test.txt)"
	"(( [ -e test.txt ] && echo A) > test.txt)"
	"(( [ -e false.txt ] || echo \"True with Quotes\") > test.txt)"
       )

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell

	echo ----------------
	cat < test1.txt
	echo ----------------
	
done

