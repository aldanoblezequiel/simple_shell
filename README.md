<h1> Simple_Shell</h1>
<br>
This is a School project for Holberton School Uruguay. We created our own Linux Shell capable of executing certain commands.
<br>
<h2> Project Learning Objectives</h2>
<br>
<p> At the end of this project, we are expected to be able to explain to anyone, without the help of Google:</P>
- Who designed and implemented the original Unix operating system
<br>
- Who wrote the first version of the UNIX shell
<br>
- Who invented the B programming language (the direct predecessor to the C programming language)
<br>
- Who is Ken Thompson
<br>
- How does a shell work
<br>
- What is a pid and a ppid
<br>
- How to manipulate the environment of the current process
<br>
- What is the difference between a function and a system call
<br>
- How to create processes
<br>
- What are the three prototypes of main
<br>
- How does the shell use the PATH to find the programs
<br>
- How to execute another program with the execve system call
<br>
- How to suspend the execution of a process until one of its children terminates
<br>
- What is EOF / “end-of-file”?
<br>
<h2> Shell Features</h2>
<br>
Our Shell is able to:
<br>
- Display a prompt and wait for the user to type a command. A command line always ends with a new line
<br>
- If an executable cannot be found, print an error message and display the prompt again
<br>
- Handle errors.Handle errors
- Handle errors
<br>
- Handle the “end of file” condition (Ctrl+D)
<br>
Our Shell is able to:
- Implement the exit built-in, that exits the shell
<br>
<h2>Flowchart</h2>
![flowchart](https://user-images.githubusercontent.com/91083276/145319159-e8e25abe-880d-4a4b-a4c3-2f8833ed4416.png)

<br>
<h2>Formal Requirements</h2>
<br>
- Allowed editors: vi, vim, emacs
<br>
- All files must be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
<br>
- All files must end with a new line
<br>
- A README.md file, at the root of the folder of the project is mandatory
<br>
- All the code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
<br>
- The shell should not have any memory leaks
<br>
- No more than 5 functions per file
<br>
- All header files should be include guarded
<br>
- Use system calls only when need to
<br>
<h2>Authors</h2>
<br>
Mateo Victorica and Ezequiel Aldabalde.
