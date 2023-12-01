# XV6-OS-Project
This project was divided into 4 parts.

# Part 1 System call tracing
Your first task is to modify the xv6 kernel to print out a line for each system call invocation. It is enough to print
the name of the system call and the return value; you don't need to print the system call arguments.

# Part 2 ps system call

Your second task is to add a new system call to xv6. The main point of the exercise is for you to see some of the
different pieces of the system call machinery.
Your new system call will get information about the processes running in the system and return it to the user
program. Specifically, your new system call will have the following interface:
int getprocinfo(int pid, struct uproc *up);
Where pid is the process id of the target process, and struct uproc is a structure that describes the process, i.e.,
contains the following information about the process: process name, process id, parent process id, size of process
memory, process state, whether process is waiting on a channel, and whether it's been killed.
You will have to define the struct uproc and implement the ps utility by querying the system about all
processes in the system. You should create a user-level program that calls your getprocinfo system call.
Since both the kernel and user level code need the definition of the struct uproc structure, we can define in
one of the header files visible at both levels. To define struct uproc look at how the same fields are defined in xv6's struct proc.
When you're done, typing ps to an xv6 shell prompt should print all processes running in the system and
information about them.
In a text file write down a few words of explanation for each of the files you had to modify in the process of
creating your getprocinfo() system call.

# Part 3 Maintaining History of commands in xv6

History of past shell commands allows terminal users to evaluate multiple requests very fast
without writing the entire command.
In this part of the assignment you will have to implement the history feature and the ability
to easily update the console to fit the needed history. In modern operating systems the
history is implemented in the shell.
To allow for a simple implementation you will implement history in kernel. Your
implementation should support a maximum of 16 commands.
To do so you can add: #define MAX_HISTORY 16 to your code.
Once history is implemented we need a way to access the history. You will implement two
mechanisms to do so:
1) The ↑ / ↓ keys will need to retrieve the next / last item in the history respectively. The
item retrieved
should now appear in the console.
2) Add a history system call:
int history(char * buffer, int historyId)
Once this is implemented add a “ history “ command to the shell user program (see sh.c) so
that it upon writing the command a full list of the history should be printed to screen like in
common.

# Part 4 Statistics

In this part we will implement an infrastructure that will allow us to examine how these
policies affect performance under different evaluation metrics.
The first step is to extend the proc struct (see proc.h).
Extend the proc struct by adding the following fields to it: ctime, stime, retime and rutime.
These will respectively represent the creation time and the time the process was at one of
following states: SLEEPING, READY(RUNNABLE)and RUNNING.
Note : These fields retain sufficient information to calculate the turnaround time and waiting
time of each
process.
Upon the creation of a new process the kernel will update the process’ creation time. The
fields (for each process state) should be updated for all processes whenever a clock tick
occurs (you can assume that the process’ state is SLEEPING only when the process is
waiting for I/O).
Finally, care should be taken in marking the termination time of the process (note: a process
may stay in the ‘ZOMBIE’ state for an arbitrary length of time. Naturally this
should not affect the process’ turnaround time, wait time, etc.). Since all this information is
retained by the kernel, we are left with the question of extracting this information and
presenting it to the user. To do so, create a new system call wait2 which extends the wait system call.
The aggregated number of clock ticks during which the process waited (was able to run but
did not get CPU) The aggregated number of clock ticks during which the process was
running. The aggregated number of clock ticks during which the process was waiting for
I/O (was not able to run).
