



#!/bin/sh




#test 1 " ls || echo hello world && exit; ls
# the exit command will execute

#test 2 " ls || exit && echo does it work
# the exit command will not  execute

#test 3 " ls; exit; echo does it?; echo maybe
# the exit command will execute


INPUTS=("ls && exit || echo hello world"
        "ls || exit && echo does it work"
        "ls; exit; echo does it?; echo maybe")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

