# libft

libft is a C library that implements a series of useful functions for string manipulation, type conversions, and mathematical operations. This library is a fundamental project for those learning C and looking to build a solid foundation in programming.

## Project Structure

The project is organized as follows:

```
libft
├── include
│   ├── ft_abs.h
│   ├── ft_boolean.h
│   ├── ft_point.h
│   ├── ft_stock_str.h
│   └── libft.h
├── srcs
│   ├── libft.c #all functions unified
│   ├── ft_atoi.c
│   ├── ft_strlen.c
│   ├── ft_putchar.c
│   ├── ft_putnbr.c
│   ├── ft_swap.c
│   ├── ft_putstr.c
│   ├── ft_split.c
│   ├── ft_itoa.c
│   ├── ft_strjoin.c
│   ├── ft_is_prime.c
│   ├── ft_recursive_factorial.c
│   └── ...
├── .vscode
│   ├── c_cpp_properties.json
│   └── settings.json
├── Makefile
├── libft_creator.sh
├── README.md
└── README.txt
```

## Compilation

To compile the library, use the `Makefile` included in the project. Simply run the following command in the terminal:

```bash
make
```

This will generate the static or dynamic library depending on the `Makefile` configuration.

## Usage

To use the library in your projects, make sure to include the main header:

```c
#include "libft.h"
```

Additionally, by running `libft_creator.sh`, you can create your library globally on your system as either a shared library (`.so`) or a static library (`.a`), so you won't need to include it manually in your projects.
Then, you can compile your program linking the library:

```bash
gcc -o my_program main.c -llibft
```



-------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------



# README

To implement custom libraries in an environment with paths that can always be used, you must follow these steps:

-------------------------------------------------------------------------------------------------------------------------------

If you want to make your library globally accessible without using sudo, the best option is to install it in your user directory and configure your environment to find it automatically.
📌 Method: Install the library in $HOME/.local
 This method allows any program to use #include "my_lib.h" without manually moving files.

1️⃣ Create installation structure
 mkdir -p $HOME/.local/include   # For headers (.h)
 mkdir -p $HOME/.local/lib       # For libraries (.a and .so)
2️⃣ Copy the files
 cp my_lib.h $HOME/.local/include/
 gcc -shared -o $HOME/.local/lib/libmy_lib.so -fPIC my_lib.c
3️⃣ Configure environment variables
 Add these lines to your ~/.bashrc or ~/.zshrc to make them permanent:

 export C_INCLUDE_PATH=$HOME/.local/include:$C_INCLUDE_PATH
 export LIBRARY_PATH=$HOME/.local/lib:$LIBRARY_PATH
 export LD_LIBRARY_PATH=$HOME/.local/lib:$LD_LIBRARY_PATH

 Then, apply the changes:
 
 source ~/.bashrc      /or/      source ~/.zshrc (if you use zsh)

🚀 Use it in any project
 Now, when compiling any program, simply do:

 gcc -o my_program main.c -lmy_lib
🔹 No need for -I or -L, because the compiler already knows where to look.
🔹 Works for any project without copying files.

🔥 Advantages of this method
✅ No need for sudo
✅ Accessible in any project without moving files
✅ Persistent, even after reboot
✅ Compatible with static (.a) and dynamic (.so) libraries

💡 Now you can use my_lib.h and libmy_lib.so globally without complications. 🚀


--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


If you already used the installation method in ~/.local, here is what you need to include and how:

📂 Content of ~/.local/include/
 This directory should only contain the headers (.h) of your library.

📌 Steps:

 cp my_lib.h $HOME/.local/include/
📌 Example of my_lib.h:

 #ifndef MY_LIB_H
 #define MY_LIB_H

 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
 #include <fcntl.h>
 #include <string.h>

 // Function prototypes
 int ft_atoi(char *str);
 int ft_strlen(char *str);
 void ft_putchar(char c);
 void ft_putnbr(int nbr);
 void ft_swap(int *a, int *b);

 #endif
🔹 It should NOT contain function implementations, only prototypes and necessary #includes.

📂 Content of ~/.local/lib/
 Here should be the compiled versions of the library in the form of static (.a) or dynamic (.so) files.

📌 Option 1: Static Library (.a)
 gcc -c my_lib.c -o my_lib.o
 ar rcs $HOME/.local/lib/libmy_lib.a my_lib.o
 This creates libmy_lib.a, which is linked during compilation.

📌 Option 2: Dynamic Library (.so)
 gcc -shared -o $HOME/.local/lib/libmy_lib.so -fPIC my_lib.c
 This creates libmy_lib.so, which is loaded at runtime.

📌 Final Configuration
 To ensure the compiler finds the library automatically, make sure to have these variables in ~/.bashrc or ~/.zshrc:

 export C_INCLUDE_PATH=$HOME/.local/include:$C_INCLUDE_PATH
 export LIBRARY_PATH=$HOME/.local/lib:$LIBRARY_PATH
 export LD_LIBRARY_PATH=$HOME/.local/lib:$LD_LIBRARY_PATH
 
 And apply the changes:

 source ~/.bashrc  # Or source ~/.zshrc if you use Zsh

🚀 How to use the library in a project
 1️⃣ Link the static library (.a):

 gcc -o my_program main.c -lmy_lib
 2️⃣ Link the dynamic library (.so):

 gcc -o my_program main.c -lmy_lib
 (If an error occurs during execution, reload LD_LIBRARY_PATH with export LD_LIBRARY_PATH=$HOME/.local/lib).

🔥 Advantages
✅ No need to copy files to each project
✅ No sudo required
✅ Compatible with any compiler (gcc, clang, etc.)
✅ You can update the library without modifying each project

Now, any C code can include #include "my_lib.h" and link with -lmy_lib without worrying about paths. 🚀

📌						Makefile Description:
 This Makefile is designed to work with a script named libft_creator.sh
 that sets up the project. The script should create the necessary files
 and directories, and the Makefile will handle the compilation of the
 source files into a static library named libft.a.
 The check_creator target ensures that the script is run only once,
 and the .creator_done file is used to track whether the script has
 already been executed.
 The script should be placed in the same directory as this Makefile.
 The script should also handle the creation of the include directory
 and the srcs directory, and any other necessary setup for the project.
 The script should also ensure that the source files are placed in the
 srcs directory and the header files are placed in the include directory.
 The script should also ensure that the Makefile is placed in the root
 directory of the project.
							How to use it:
 Make sure the libft_creator.sh file is in the same directory as the Makefile.
 Run make as usual. If the script has not been executed before,
 it will run automatically. If you need to force the script to run again,
 use make fclean followed by make.