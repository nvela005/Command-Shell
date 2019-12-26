#!/bin/sh

#test 1 "cat < test.txt"
#test 2 "sort < test.txt > test1.txt"
#test 3 "cat < test.txt || echo TestFailed"
#test 4 "cat < false.txt || echo TestPassed"

#test 5 "sort < test.txt && echo TestPassed"
#test 6 "sort < false.txt && echo TestFailed"
#test 7 "((( test -e test.txt && echo A) > test.txt) && sort < test.txt)"


INPUTS=("cat < test.txt"
        "sort < filename > test1.txt"
        "cat < test.txt || echo TestFailed"
	"cat < false.txt || echo TestPassed"

	"sort < test.txt && echo TestPassed"
	"sort < false.txt && echo TestFailed"
	"(((test -e test.txt && echo A) > test.txt) && sort < test.txt)"
       )
for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

