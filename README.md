**Simple Shell**

**Overview**

The simple shell is a command processor that mimics the C shell allowing the user to type commands. This project was developed as a part of first year curriculum of Holberton School, San Fransisco.

**Usage**

1. All the prototypes are included in shell.h.
2. Compile using gcc -Wall -Werror -Wextra -pedantic * .c -o hsh
3. waits for a comand from the user after printing the prompt.
4. Checks for built-ins, aliases, executables in the path.
5. Creates child process.
6. When it is done, the program returns to parent.
7. Ctrl-D(End of file) ad exit.

**Features**

Like the C shell, simple shell handles command line inputs along with arguments.
Some of the following built-ins are implemented.They are,

| No. | command | Description |
| --- | ------- | ----------- |
| 1. | Exit | Exits simple shell |
| 2. | env | Prints list of environment variables |
| 3. | Ctrl-D | end of file(exits the shell) |

**examples**

$ ls -l

total 68
-rw-r--r--  1 sneha sneha   515 Apr 17 04:24 built_in.c
-rw-r--r--  1 sneha sneha  1158 Apr 17 04:24 handle_arg.c
-rwxr-xr-x  1 sneha sneha 23960 Apr 12 17:31 simple_shell_main.c
-rw-r--r--  1 sneha sneha  1816 Apr 17 04:24 path.c

$ pwd

/home/sneha/simple_shell

**About**

All files were created and compiled on Ubuntu 14.04.4 LTS using GCC 4.8.4 with the flags "-Wall -Werror -Wextra -pedantic".

**Files**

| Files | Description |
| ----- | ----------- |
| simple_shell_main.c | entry point |
| shell.h | function prototypes, standard libraries |
| built_in.c | executing built-ins for shell |
| handle_args.c | tokenizing function |
| path.c | path(path value, splitting and getting commands) |
| please_enter.c | reading the buffer input(getline) |
| strhelp.c | helper functions needed to create this shell project |
| _putchar.c | writes the character to stdout |
| _puts.c | update the value it points to |
| AUTHORS | contributors to the simple shell project |

**Authors**

**Van Duy Phan** - @Van_D_Phan
**Sneha Dasa Lakshminath** - @DasaSneha
