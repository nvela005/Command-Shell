



#!/bin/sh



# test #1  "(echo A || echo B) && (echo C || echo D)" command

# test #2  "(ls; echo B) || (mkdir anime && rm -rf anime)" command

# test #3  "(test -e ../header || echo error); ( [ -f ../header ] && echo test passed)" command

# test #4  "[ -d ../header ] && (ls || (echo D && echo B))" command

# test #5  "((test -f ../header || echo test passed) || echo error); (echo pass || echo error)" command

# test #6 "(echo "hell) world" || echo test failed) && echo "(cs major)""

# teset #7 "(echo D || echo B) && (echo C"

INPUTS=("(echo A || echo B) && (echo C || echo D)"
	"(ls; echo B) || (mkdir anime && rm -rf anime)" 
	"(test -e ../header || echo error); ( [ -f ../header ] && echo test passed)"
	"[ -d ../header ] && (ls || (echo D && echo B))"
	"((test -f ../header || echo test passed) || echo error); (echo pass || echo error)"
	"(echo \"hell) world\" || echo test failed) && echo \"(cs major)\""
	"(echo D || echo B) && (echoC")
for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

