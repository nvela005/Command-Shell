




#!/bin/sh


#test #1 ls -a; echo hello; mkdir test
#all three commands will execute

#test #2 ls || echo hello || ls
#only the first command will execute

#test #3 ls || echo hello && ls
#only the first and third command will execute

#test #4 ls -a; echo hello && mkdir test || echo world; git status
#echo world will not execute

#test #5 echo "hello && world" || cd asda && ls
#only the first command will execute


INPUTS=("ls -a; echo hello; mkdir"
        "ls || echo hello || ls" 
        "ls || echo hello && ls"
	"ls -a; echo hello && mkdir test || echo world; git status"
        "echo \"hello && world\" || cd asda && ls")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done



