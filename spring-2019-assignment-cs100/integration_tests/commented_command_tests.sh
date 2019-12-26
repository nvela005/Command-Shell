


#!/bin/sh





# test 1 " # hello world i am a cs a major "
# program executes no command just returns

# test 2 " ls # -a && ls  "
# program executes ls

# test 3 " ls || echo "hello # world" "
# program executes entire line of commands

# test 4 " mdkir test && rm -rf test # "
# program executes entire line of commands

INPUTS=("# hello world I am a cs major"
        "ls # -a && ls"
	"ls || echo \"hello # world\""
        "mkdir test && rm -rf test #  ")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

