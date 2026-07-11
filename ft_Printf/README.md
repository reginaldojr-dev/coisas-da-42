*This project has been created as part of the 42 curriculum by rgoulart.*

# ft_printf

## Description

`ft_printf` is a 42 School project whose goal is to recreate part of the behavior of the standard C function `printf()`.

The project consists of building a static library called `libftprintf.a`, containing the function:

```c
int ft_printf(const char *format, ...);
```

The main purpose of this project is to understand how variadic functions work in C, how formatted output is parsed, and how different data types can be converted and written to the standard output.

Unlike the original `printf()`, this implementation does not reproduce the internal buffer management of the libc version. The focus is on correctly parsing the format string, handling the required conversions, printing the expected output, and returning the correct number of printed characters.

## Features

The mandatory implementation supports the following conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal number |
| `%i` | Prints a signed integer in base 10 |
| `%u` | Prints an unsigned decimal number |
| `%x` | Prints an unsigned number in lowercase hexadecimal |
| `%X` | Prints an unsigned number in uppercase hexadecimal |
| `%%` | Prints a percent sign |

## Project Structure

A possible structure for the project is:

```text
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_putchar.c
├── ft_putstr.c
├── ft_putnbr.c
├── ft_putunsigned.c
├── ft_puthexadecimal.c
├── ft_putpointer.c
└── README.md
```

The final library must be generated at the root of the repository with the name:

```text
libftprintf.a
```

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This command must generate:

```text
libftprintf.a
```

The project must be compiled using:

```bash
cc -Wall -Wextra -Werror
```

The `Makefile` must include at least the following rules:

```bash
make
make all
make clean
make fclean
make re
```

### Example of Use

Create a small `main.c` file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

Compile it with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Run:

```bash
./test
```

Expected output:

```text
Hello, 42!
Number: 42
Hex: ff
```

## Technical Explanation

### Variadic Functions

The original `printf()` can receive an unknown number of arguments. To reproduce this behavior, `ft_printf` uses variadic functions from `<stdarg.h>`.

The main macros used are:

| Macro | Purpose |
|---|---|
| `va_start` | Initializes access to the variable argument list |
| `va_arg` | Retrieves the next argument from the list |
| `va_copy` | Copies a variable argument list when necessary |
| `va_end` | Cleans up the variable argument list |

The function reads the format string character by character. When it finds a `%`, it checks the next character to identify which conversion must be executed.

### Parsing Strategy

The project uses a simple linear parsing strategy.

The format string is traversed from left to right:

1. If the current character is not `%`, it is printed normally.
2. If the current character is `%`, the next character is treated as a conversion specifier.
3. The matching function is called according to the conversion.
4. The number of printed characters is accumulated and returned at the end.

This approach is appropriate because the mandatory part only requires simple conversions, without complex formatting rules such as width, precision, or flags.

## Algorithm and Data Structure Justification

### Chosen Algorithm

The chosen algorithm is a sequential parser over the format string.

This means the function processes each character once, from the beginning to the end of the string. This is enough because each conversion specifier can be detected locally by reading the `%` character and the character immediately after it.

The general logic is:

```text
start count at 0
start variadic argument list
for each character in format:
    if character is not '%':
        print character
        increase count
    else:
        move to next character
        identify conversion
        print the corresponding argument
        increase count by the number of printed characters
end variadic argument list
return count
```

### Why This Algorithm Was Chosen

This algorithm was chosen because it is simple, readable, and efficient for the requirements of the mandatory project.

Its complexity is linear:

```text
O(n)
```

Where `n` is the length of the format string, plus the number of digits needed to print numeric arguments.

No complex data structure is necessary because the format string can be processed directly with an index or pointer.

### Data Structures Used

The project mainly uses:

| Data Structure | Reason |
|---|---|
| `const char *` | Used to read the format string |
| `va_list` | Used to access the variable arguments |
| `int` counter | Used to store and return the number of printed characters |
| Recursive or iterative number conversion | Used to print decimal and hexadecimal numbers |

A `va_list` is the central structure of the project because it allows `ft_printf` to access arguments whose types are only known after parsing the conversion specifier.

## Conversion Handling

### Characters and Strings

For `%c`, the argument is received as an `int`, then printed as a character.

For `%s`, the argument is received as a `char *`. If the string is `NULL`, the implementation should handle it safely, commonly by printing `(null)`, matching the expected behavior in many printf implementations.

### Numbers

For `%d` and `%i`, the argument is treated as a signed integer.

For `%u`, the argument is treated as an unsigned integer.

For `%x` and `%X`, the number is converted to base 16. The lowercase version uses:

```text
0123456789abcdef
```

The uppercase version uses:

```text
0123456789ABCDEF
```

### Pointers

For `%p`, the pointer is received as `void *` and printed as a hexadecimal address, usually prefixed with:

```text
0x
```

The pointer value should be converted using an unsigned integer type capable of storing an address, such as `unsigned long`.

## Return Value

`ft_printf` returns the total number of characters printed.

Example:

```c
int len;

len = ft_printf("abc");
```

In this case, `len` should be:

```text
3
```

This behavior is important because the project is compared against the original `printf()`.

## Authorized Functions

According to the project subject, the authorized external functions are:

```text
malloc, free, write,
va_start, va_arg, va_copy, va_end
```


## Testing

Although tests are not submitted, creating local tests is strongly recommended.

Useful cases to test:

```c
ft_printf("%c\n", 'A');
ft_printf("%s\n", "Hello");
ft_printf("%p\n", &value);
ft_printf("%d\n", -42);
ft_printf("%i\n", 42);
ft_printf("%u\n", 4294967295u);
ft_printf("%x\n", 255);
ft_printf("%X\n", 255);
ft_printf("%%\n");
```

It is also useful to compare the output and return value with the original `printf()`.

Example:

```c
int a;
int b;

printf("Original: ");
a = printf("%d\n", 42);

ft_printf("Custom: ");
b = ft_printf("%d\n", 42);

printf("printf returned: %d\n", a);
printf("ft_printf returned: %d\n", b);
```

## Resources

Useful references for this project:

- `man 3 printf`
- `man 2 write`
- `man stdarg`
- C documentation about variadic functions
- 42 project subject: `ft_printf`
- Peer discussions and evaluations at 42

## Use of AI

AI was used as a learning and documentation support tool, mainly to help organize explanations, structure the README, and clarify concepts related to variadic functions, parsing strategy, and project documentation.

AI was not used as a replacement for understanding the project logic. The implementation, debugging, testing, and defense preparation must be based on personal reasoning, manual practice, and peer learning, following the learning principles of the 42 curriculum.

## Author

Created by `rgoulart` as part of the 42 curriculum.
