*This project has been created as part of the 42 curriculum by <ribresci>.*

# ft_printf

## Description

**ft_printf** is a reimplementation of the standard C `printf()` function.  
The goal of this project is to gain a deeper understanding of variadic functions, formatted output, and low-level data manipulation in C, while respecting the constraints imposed by the 42 curriculum.

This implementation reproduces the behavior of the original `printf()` for a limited set of format specifiers. Buffer management from the original function is intentionally not implemented. The project is delivered as a static library named `libftprintf.a`, which can be reused in other C projects.

The function is compared directly against the original `printf()` to verify correctness.

### Supported conversions

The following format specifiers are implemented:

- `%c` : Prints a single character  
- `%s` : Prints a string  
- `%p` : Prints a pointer address in hexadecimal format  
- `%d` : Prints a signed decimal number  
- `%i` : Prints an integer in base 10  
- `%u` : Prints an unsigned decimal number  
- `%x` : Prints a hexadecimal number (lowercase)  
- `%X` : Prints a hexadecimal number (uppercase)  
- `%%` : Prints a percent sign  

### Compilation

To compile the project, run:

make

This will generate the static library:

libftprintf.a