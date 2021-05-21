# OSprogramming
Some OS topics fork,exec etc codes.
Q1)Considering name e.g Khajasta Zainab  draw a binary tree on paper according to the
given implications.
Tree will be of your full name, using upper case alphabet. Less character will be
moved to left, greater and equal will be drawn on right side. If your name is
composed of three names first, middle and last just take your middle and last
name as full name. Also no need to take space between name.
Part 2:
Write a C/C++ program in Linux platform of your full name as refers to the
generated tree in PART 1.
Each node has to display its parent id, child id, letter and ASCII value.
e.g. Node H: “PPID: 1223, PID: 1234 and ASCII: 072”

Each child will return its character with value as ASCII to the parent. All the
parent node will add the child letter in its display statement.
e.g. Node E: “PPID: 2223, PID: 2234 and ASCII: 083 My child is H”
At the end parent will display the final output as sum of all characters. E.g. Parent
M will get both the E and R sub trees ASCII values and will sum their return
values. It should be a positive integer value.
You have to use wait () system call for properly displaying the statements and
tree hierarchy from bottom up view.


Q2)Write a program that receives one command line argument: the name of a text
file. Your program will work as follows:
 Start out by creating a child process.
 The child process calls exec to run cat command with command line
argument that the parent received.
 The parent process calls wait so that it blocks until the child terminates and
passes back its termination status.
 If the child process terminates without error, the parent spawns another
child and, again, calls wait so that it can block until the child terminates.
 The new child calls exec again, but this time it runs wc command on the
same argument that the parent received from the command line.
 Once the parent learns that the child has terminated, it goes on to
terminate also. If the parent gets to this point, it’s because all has gone well.


Q3)Write your shell program which take input commands/exe’s from user as your
shell takes and execute them. Your shell will terminate when user enter “quit”.
Your shell program should be able to handle arguments of commands/exe’s


Q4)Write a program which take string from user and you have to do following tasks
with the string.
1. Reverse
2. Find Length
3. Add 2 in the ASCII of each character
4. Sort
5. Capitalize
You have to create child of child’s as given below process tree for each task and
each child exec with the image of program of particular task. Print the string after
each operation.
