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
├── src
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
