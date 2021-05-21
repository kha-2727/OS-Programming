# OSprogramming
___________________******************Fork****************___________________



Some OS topics fork,exec etc codes.
Q1)Considering name e.g Khajasta Zainab  draw a binary tree on paper according to the
given implications.      (SOLUTION IN FILE NAMEBINARYTREE.CPP)
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
file. Your program will work as follows:  (SOLUTION IN FILE COMMANDINPUT.CPP)
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
Your shell program should be able to handle arguments of commands/exe’s (SOLUTION IN FILE CAT_WC_COMMAND.CPP)


Q4)Write a program which take string from user and you have to do following tasks
with the string.  (SOLUTION FILES ADD2.CPP, REVERSE.CPP, CAPITAL.CPP, SIZE.CPP , SORT.CPP ,MAINOFALL.CPP)
1. Reverse
2. Find Length
3. Add 2 in the ASCII of each character
4. Sort
5. Capitalize
You have to create child of child’s as given below process tree for each task and
each child exec with the image of program of particular task. Print the string after
each operation.

_________*************** Pipes *****************_______________


Q1)Write a program that find frequent item-set of grocery store data. You program will take
data file as command line argument.  (SOLUTION FILE GROCERYFREQ.CPP)
Format and Sample of Data File:
0.5
6
Paratha, Makhan, Anda, Sharbat
Paratha, Makhan, Sharbat
Paratha, Doodh, Dahi
Paratha, Sharbat, Doodh
Makhan, Sharbat, Doodh
Paratha, Anda, Makhan, Sharbat

In this sample data file o.5 is support threshold, 6 is no of transactions and the remaining
are transactions.
Step 1: [5 marks]
Create child1 using fork in parent

After fork Parent process read the file and store the data. Evaluate the value of
threshold = support threshold x no of transactions.
For given example threshold = 0.5 x 6 => 3
Now parent process send value of threshold and all the transactions to the child1 using
unnamed pipe.
Step 2: [5 marks]
Child1 have to find the frequency of all the items as shown in below table and print it on
terminal.

Items Frequency
Paratha 5
Makhan 4
Anda 2
Sharbat 5
Doodh 3
Dahi 1

After that remove the items that have frequency less than threshold value and print it
on terminal.

Items Frequency
Paratha 5
Sharbat 5
Makhan 4
Doodh 3

Now Child1 creates Child2 and send the above items and their frequencies, andtransactions to Child2 using unnamed pipe.

Step 3: [5 marks]
Child2 find 2-item pair frequencies and print it on terminal as shown below.

Items Frequency
Paratha, Makhan 3
Paratha, Sharbat 4
Paratha, Doodh 2
Makhan, Sharbat 4
Makhan, Doodh 1
Sharbat, Doodh 2

After that remove the items that have frequency less than threshold value and print it
on terminal.
Item Frequen
cy
Paratha, Sharbat 4
Paratha, Makhan 3
Makhan, Sharbat 3

Now Child2 creates Child3 and send the above items and their frequencies, and
transactions to Child3 using unnamed pipe.

Q2)Write two different programs P1 and P2 that will connect through a pipe and chat with
one another. P1 process will take the total and obtained marks of all the assessments of
OS Lab shown from user and send this data to P2. P2 process will calculate the absolutes
marks of each assessment, calculate total absolutes and calculate the grade using absolute
grading policy of Fast. Also print these on terminal.  (SOLUTION FILES READING.CPP WRITING.CPP)

Q3)grep a *.* | sort | sum | wc
Write a code for the above commands using unnamed pipe and dup. (SOLUTION FILE COMMANDS.CPP)

