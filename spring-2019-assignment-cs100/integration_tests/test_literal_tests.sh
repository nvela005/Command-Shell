

#!/bin/sh



# test #1  "test -e ../header/ctree.hpp" command
# test #2  "test -f ../header/ctree.hpp" command
# test #3  "test -d ../header/ctree.hpp" command
# test #4  "test ../header/ctree.hpp" command

INPUTS=("test -e ../header/ctree.hpp"
        "test -f ../header/ctree.hpp" 
	"test -d ../header/ctree.hpp"
        "test ../header/ctree.hpp")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

#test #5 "test -e ../header" command
#test #6 "test -f ../header" command
#test #7 "test -d ../header" command
#test #8 "test ../header" command

INPUTS=("test -e ../header"
	"test -f ../header"
	"test -d ../header"
	"test ../header")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

#test #9 "test ../header || echo failed"
#test #11 "test -f ../header; echo test passed"
#test #12 "test -d ../header/ctree.hpp && echco test failed"
#test #13 "echo D; exit && test -f ../header"

INPUTS=("test ../header || echo failed"
	"test -f ../header; echo test passed"
	"test -d ../header/ctree.hpp && echco test failed"
	"echo D; exit && test -f ../header")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

