### CS100:
Navin Velazco 861246406 <br/>
Hoda Farhat   862015738

## Introduction:

This program is a basic command shell named Rshell. It will print out a prompt to let the user know the program is ready to receive input. Rshell will take in a line of commands; they are in the form $ executable [argument list] [connector] from standard input that are chained together with the ||, &&, and ; operators. These are known as connectors. The program will then analyze the chain of commands and separate the chain into individual commands using a few usermade functions. The commands and operators will be constructed into a tree following a composite pattern structure, where a complex chain of commands is built from linking an individual command and a chain of commands with a connector. Since the connectors are used to form more complex commands, they will form the composite objects, and the indivdual commands will be the leaf objects for the hierarchical tree structure. The commands are executed in the order they were typed and a call to execute the last chained command will trigger down the tree to keep the order of execution consistent.

The test command in our rshell will return 0 if the test succeeds and 1 if the test fails. We can use the test command to write more complicated commands into our rshell. In addition, we can add flags to the test command. The -e flag, the default flag, checks if the file/directory exists. The -f and -d flag both check if the file/directory exists, but the -f flag also checks if it is a regular file, and the -d flag checks if it is a directory.

One can also use precedence operators,'(' and ')', to change the order of items that are executed. For example, if one types (ls && echo B || echo C || echo D && ls) into rshell, the result will be ls, B, and ls. However, if one uses precedence operators around ls and echo B and precedence operators around echo D and ls((ls && echo B) || echo C || (echo D && ls)), the result will be ls and B. If the precedence operators are used incorrectly, such as missing an opening or closing parenthesis, rshell will return an error.

R'shell can also handle input redirection, output redirection, and piping. Input redirection can be done using the (<) character. Using this command will change the standard input from the keyboard to a file. Output can be redirected using the (>>) or (>). These wil display the output in a file. Using (>) will write the output to a file, but if one repeats the command to write to the same file, (>) will overwrite previous redirections. In order to append the current output to previous ouputs, one would use (>>). Piping allows many commands to be put together using (|). Using pipes allows the output of one command to be to directed into the input of a different command.  
   
## Diagram

![alt text](https://github.com/cs100/spring-2019-assignment-cs100/blob/master/images/Capture.PNG)

Suppose we have this chain of commands:  <br/>
**ls -1 || mkdir hello && rm hellit.txt || cd mathdocs; ls** <br/> The tree representation will look like this:


![alt text](https://github.com/cs100/spring-2019-assignment-cs100/blob/master/images/capture2.PNG)

## Classes:
The subclasses command, orop, colonop,and andop all inherit from the same abstract base class. The base class declares a pure virtual function int RunCommand that will be implemented by each of the subclasses and returns 0 if the execution was successfull or it didn't run. It will return -1 if the command didn't execute successfully. Based on this return value the command under an operator may or may not execute. The base class will also declare and implement the two non virtual functions, addlop and addrop since the implementation is the same for the three composite objects. The base class will not contain any private members since the composite and leaf objects will not contain the same data members. Orop, andop, and colonop will implement RunCommand by passing the request to their children while the command object is an individual object that will handle this request directly. Command contains a string a private member which contains the executable and its arguments. The composite objects have an object base pointer pointing to a chain of commands or a command and an object command pointer as its internal members. Complex chains of commands are built from linking smaller chains to indivdual commands using any of the three operators.


## Prototypes/Research

If I want to call execvp to run the chain of commands then the program will terminate after the first command is successfully executed. That means if I try to run execvp in the parent process, we won't be able to run the rest of the commands if there are multiple. To avoid this problem we will use the system call fork().

By calling fork() we are creating a copy of the current process known as a child process where anything that is done in the child process does not affect the main process. This means we can run commands in the child process without terminating the parent process. To avoid "zombie" processes, we can use waitpid() to tell the parent process to wait for the child process to terminate. In this assignment we'll keep calling fork to execute each command in the child process. That way the parent process doesn't terminate before all the commands are finished executing.

Let's say I run this chain of commands on the terminal, ls || ls || ls. If the first command executes successfully, then the second command will not execute. When we get to the third command, ls won't execute even though the previous executable didn't fail. If instead we have this chain of commands, ls || ls && ls and the first command executes successfully then the second command will not execute. When we reach the third command, ls will execute even though the second command never executed successfully.

## Development and Testing Roadmap:

[1. Print a prompt to the screen requesting input from the user][1] unit test <br/>
[2. Write a function that will take in a string and return an int vector containing the indices where quotes are found][3] unit test <br/>gg
[3. Write a function that will take in an int vector and an integer and will return the greatest indice that has a value less than the integer][4] unit test <br/>
[4. Write a function that takes in a string of text and returns the uncommented part][2] unit test <br/>
**As this point write an integration test using the three functions created so far** <br/>
[5. Write a funcion that takes in a string and removes all quote characters from the string] unit test <br/>
[6. Write a function that modifies a vector of Base* objects and a vector of strings][5] unit test <br/>
[7. Declare the interface for the base class and its subclasses] <br/>
[8. Implement addlop and addrop for the composite objects][7] <br/>
[9. By creating a mock and getcommand() function unit test addlop and addrop] <br/>
[10. Write a function that will create a chain commands using the Base class and its subclasses][6] unit Test <br/>
**As this point write an integration test to see if base class constructs a chain of commands correctly** <br/>
[11. Implement the RunCommand for the command object using fork() execvp() , and waitpid()][8] unit test <br/>
[12. Implement the RunCommand for the composite objects][9] unit test using mocks <br/>
[13. Create a special built in command, exit()][10] unit test <br/>
14. Implement the test command using the stat function, as well as the ISREG and IS DIR  function. <br/>
15. Create a Precedence class that checks to see where the parentheses are in a string of commands, and execute those commands with precedence first. If there are missing opening and closing parentheses, an error will be returned. <br/>
16. Create a function that allows the user to redirect input and output. If a user enters (<), redirect the input from a file. If the user enters (>) or (>>), redirect the output to a file. <br/>
17. Add a Pipe class that allows more that one command to be executed at the same time by taking the output of a command and directing it to the input of second command. </br> 
**Final integration test, constructs the tree correctly and executes the tree correctly by writing bashscripts**

[1]: https://github.com/cs100/spring-2019-assignment-cs100/issues/1
[2]: https://github.com/cs100/spring-2019-assignment-cs100/issues/2
[3]: https://github.com/cs100/spring-2019-assignment-cs100/issues/3
[4]: https://github.com/cs100/spring-2019-assignment-cs100/issues/4
[5]: https://github.com/cs100/spring-2019-assignment-cs100/issues/5
[6]: https://github.com/cs100/spring-2019-assignment-cs100/issues/6
[7]: https://github.com/cs100/spring-2019-assignment-cs100/issues/7
[8]: https://github.com/cs100/spring-2019-assignment-cs100/issues/8
[9]: https://github.com/cs100/spring-2019-assignment-cs100/issues/9[10]: https://github.com/cs100/spring-2019-assignment-cs100/issues/10
