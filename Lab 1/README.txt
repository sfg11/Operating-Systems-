** Description Lab 1 **
                   
1. Write two small c programs.  

a). The first program "pre.c" 
should read in a list of student names and their GPAs. To be simple, you can just input the 
students' first names. Enter the inputs through the keyboard and display the output on the screen. 
The input ends when an EOF is encountered. The output of the program should display the students 
whose GPAs are above 3.0. 
 
For example, the following are the inputs to "pre.c". 

Susan 3.1
John 2.0
David 3.5
Jessica 3.4 
Ctrl-D (to terminate the input.)
         
    then "pre.c" produces the output: 
Susan
David
Jessica

Note: an EOF is usually 'sent' to a process by hitting a CTRL_D.  
If you type stty -an on your unix command line, you can get info that 
tells you which keyboard keys mean what. FYI, in c, to put values to 
standard_out  use printf().  To get values from standard_in use scanf() 
or getchar(). 

b). The second program "sort.c" reads in a list of student names from the keyboards and 
displays them in alphabetical order on the screen. Assume the sequence is read until 
an EOF is encountered. 

If the inputs are:

Susan
David
Jessica

The outputs should be:

David
Jessica
Susan
 

2. Write a c program to set up a child-TO-parent pipe; the child 
should 'exec' to perform a "pre" process and its output should be 
connected to the pipe connected to the parent, which should 'exec' to 
perform a "sort" process.

3. Write a program to take a UNIX command from the command line
and fork() a child to execute it. The command can be a simple 
command like: $ls or $ps, Or it can be a command with options such as
$ls -t -l. Use argc and argv[] in the main function to pass parameters.
When the child process is executing the command, the parent process 
simply waits for the termination of the child process. The process 
id of the parent and the child should be printed out using getpid() and
getppid() functions.
---

**To execute**

gcc pre.c -o pre
gcc sort.c -o sort
gcc pipe.c -o pipe
./pipe 
To terminate: Ctrl-D
