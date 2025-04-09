# README

This directory contains `.c` files that are programs with function calls. These functions are expected to be located in `$(HOME)/.local/srcs/*.a` (or `*.so` for shared libraries).

The program itself is just a `main` function. To use it, you need to compile it with the appropriate compiler, such as `gcc`, to generate the executable. Once compiled, you should place the resulting executable in your `$(HOME)/.local/bin/` directory if you want to be able to call it directly from the terminal.