*This project has been created as part of the 42 curriculum by tisilva.*
# ft_printf
## Table of Contents

1. [Description](#description)
2. [Implemented Conversions](#implemented-conversions)
3. [Instructions](#instructions)
4. [Resources](#resources)

## Description

The **ft_printf** project consists of recreating the standard C `printf()` function.

The goal is to understand variadic functions, argument handling, type conversions and formatted output in C.

The project produces a static library called `libftprintf.a`.

## Implemented Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned integer |
| `%x` | Prints a hexadecimal number (lowercase) |
| `%X` | Prints a hexadecimal number (uppercase) |
| `%%` | Prints a percent sign |

## Instructions

### Compilation

To compile the library:

```bash
make
```

To remove object files:

```bash
make clean
```

To remove object files and the library:

```bash
make fclean
```

To rebuild the library:

```bash
make re
```

### Usage

Include `ft_printf.h` in your source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    return (0);
}
```

Compile your program using:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

Run it:

```bash
./program
```

## Resources

- 42 ft_printf subject
- Linux manual pages: `printf(3)`, `write(2)` and `stdarg(3)`
- C documentation: variadic functions and type conversions
- AI tools were used only for research purposes.

# ft_printf
