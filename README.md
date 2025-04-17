# minitalk
A project based on Linux Signals

The aim of this project is to create a small chatting program, between two processes - a server and a client - taking advantage of UNIX signals.

--- 

## IMPORTANT CONCEPTS

### SIGNALS

What is exactly a signal? In essence a signal is a way for processes to communicate with each other, each signal has a specific number associated to it and if you have ever programmed in C you have definitely come across at least one of them : **SEGFAULT** (signal number : 11). 
What's happening when you receive a **SEGFAULT** is that your program tried to access a region of memory that is protected, this caused the CPU to raise an error that is managed by the kernel, what the kernel does is notify your process of this error raised by the CPU and it does so by sending a **signal** to your process.
When a process receives a signal it has to react, the way processes react to signals is by calling a **signal handler** which can be defined as a routine (you might think of it as a function) that manages the behavior of the program when a specific signal is received.
An important thing about signals is that if your program does not define its own handlers for signal there are **default handlers** associated with signals that are called automatically to trigger a specific behavior, there are 5 different default behaviors :

- 1. `TERMINATE`             : The program quits execution, as if _exit() was called.
  2. `TERMINATE (core dump)` : As with `TERMINATE` but in this case in addition to exiting the program creates a core file where it stores relevant information about the state of the program at the moment of crash. In Linux usually this file is stored in the `/var/lib/systemd/coredump/` folder, and you can also see the recent core dumps with the associated signal with the `coredumpctl` command.
  3. `STOP`                  : Stop the process. The process is frozen and can be later resumed by sending a new signal, the difference here with `TERMINATE` is that the process still exists.
  4. `CONTINUE`              : Resume the execution of the process if it's stopped.
  5. `IGNORE`                : Ignore the signal and continue the execution of the process.
 
As you can see the system is already quite prepared for dealing with signals, for the sake of completeness here is also a list of the most important signals in UNIX with their default behavior associated and number:

- SIGSEGV - Number : 11 - Default Behavior : Terminate (core dump) (Happens when the program tries to access an invalid memory)
- SIGFPE - Number : 8 - Default Behavior : Terminate (core dump) (Happens when the program does a wrong arithmetic operation, for example divide by 0)
- SIGKILL - Number : 9 - Default Behavior : Terminate (core dump) (The program is dead, the kernel killed it)

For a complete list you can check **[this](https://en.wikipedia.org/wiki/Signal_(IPC))** article.

---

### ATOMIC INSTRUCTIONS

Atomic instructions are a way to make your CPU explode... I'm kidding but it would be fun if they were for real like that!
Ok but what are atomic instructions? Well to understand better what they are we need to see how instructions are carried out by the CPU, let's suppose we have the following program :
```c
int counter = 0;

void increase()
{
        counter++;
}

int main(void)
{
        return (0);
}

```

Compiling with `gcc -O0 -c main.c` and then doing `objdump -d main.o` to take a look at the assembly code, we can see that the line `counter++` gets translated to something like this:

```assembly
mov    0x0(%rip),%eax 
add    $0x1,%eax
mov    %eax,0x0(%rip) 
```

To carry out this operation (increasing the counter by 1) the CPU has to do 3 separate instructions, so what happens if a signal arrives to our program while the CPU is completing this job? The CPU will stop where it is (let's suppose at the  `mov    0x0(%rip),%eax`  instruction) and the signal handler will be called and executed, leaving the value of counter unchanged. This is bad, most likely some part of our program is depending on the value of this counter and we need to make sure that when we increase the value of the counter nothing can stop the CPU from executing the 3 instructions needed to do so.
Atomic instructions will do the job, in essence atomic instructions are a set of operations that the CPU will execute all together without the possibility of getting interrupted in the meanwhile. 
In our case we can take advantage of the GCC intrinsic `__sync_fetch_and_add`, which will create an atomic instruction to increase the value of counter, our `increase` function now will look like this:
```c
void increase()
{
    __sync_fetch_and_add(&counter, 1);
}
```
And when we take a look at the assembly code we will see now that the increase function is this :
```assembly
lock addl $0x1,0x0(%rip)
```
That's it! A single nice and clean operation that does everything in one go!
For this reason there's a specific type of variable in C called `sig_atomic_t` that takes advantage of this concept and is suggested to define variables that we are using in signal handlers as `sig_atomic_t`, you can take a look at [this](https://www.gnu.org/software/libc/manual/html_node/Atomic-Types.html) article from the GNU Manual to learn more about it.

---

### CONCEPTS TO RESEARCH 

- Compiler intrinsics (`__sync_fetch_and_add` is one of them but there are much more )
- Threads
- Interrupts

That's it, as always if you find any typo/inaccuracy don't hesitate to reach me out!
