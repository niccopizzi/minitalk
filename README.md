# minitalk
A project based on Linux Signals

The aim of this project is to create a small chatting program, between two processes - a server and a client - taking advantage of UNIX signals.

-- 

## IMPORTANT CONCEPTS

### SIGNALS

What is exactly a signal? In essence a signal is a way for processes to communicate with eachother, each signal has a specific number associated to it and if you program in C you have for sure come across at least one of them : **SEGFAULT** (signal number : 11). 
What's happening when you receive a **SEGFAULT** is that your program tried to access a region of memory that is protected, this caused the CPU to raise an error that is managed by the kernel, what the kernel does is notify your process of this error raised by the CPU and it does so by sending a **signal** to your process.
When a process receives a signal it has to react, the way processes react to signals is by calling a **signal handler** which can be defined as a routine (you might think of it as a function) that manages the behavior of the program when a specific signal is received.
An important thing about signals is that if your program does not define its own handlers for signal there are **default handlers** associated with signals that are called automatically to trigger a specific behavior, there are 5 different default behaviors :

- 1. `TERMINATE`             : The program quits execution, as if _exit() was called.
  2. `TERMINATE (core dump)` : As with `TERMINATE` but in this case in addition to exiting the program creates a core file where it stores relevant information about the state of the program at the moment of crash. In Linux usually this file is store in the `/var/lib/systemd/coredump/` folder, and you can also see the recent core dumps with the associated signal with the `coredumpctl` command.
  3. `STOP`                  : Stop the process. The process goes on freeze and can be later resumed by sending a new signal, the difference here with `TERMINATE` is that the process still exists.
  4. `CONTINUE`              : Resume the execution of the process if it's stopped.
  5. `IGNORE`                : Ignore the signal and continue the execution of the process.
 
As you can see the system is already quite prepared for dealing with signals, for the sake of completeness here is also a list of the most important signals in UNIX with their default behavior associated and number:

- SIGSEGV - Number : 11 - Default Behavior : Terminate (core dump) (Happens when the program tries to access an invalid memory)
- SIGFPE - Number : 8 - Default Behavior : Terminate (core dump) (Happens when the program does a wrong arithmetic operation, for example divide by 0)
- SIGKILL - Number : 9 - Default Behavior : Terminate (core dump) (The program is dead, the kernel killed it)

For a complete list you can check **[this](https://en.wikipedia.org/wiki/Signal_(IPC)** article.

---

### ATOMICAL INSTRUCTIONS

Atomical instructions are a way to make your CPU explode... I'm kidding but it would be fun if they were for real like that!
Ok but what are atomical instructions? Well to understand better what they are we need to see how instructions are carried out by the CPU, let's suppose we have the following line of code in our program :
```c
counter++;
```
In assembly  this line will be translated to something like this:

```assembly
mov eax, [counter]  ; load the value of counter from memory
add eax, 1          ; increment the value of counter
mov [counter], eax  ; store back the value to memory
```

These are 3 separate instructions that the CPU carries out one at the time, if, by any chance, our program receives a signal during this time 
