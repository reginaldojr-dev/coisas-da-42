*This project has been created as part of the 42 curriculum by rgoulart.*

# Get Next Line

## Description

**Get Next Line** is a 42 School project whose objective is to implement a function capable of reading a file descriptor **one line at a time**.

The function must preserve its reading state between consecutive calls, returning each line in sequence while correctly handling files, standard input (`stdin`), end-of-file (EOF), and different `BUFFER_SIZE` values.

---

## Algorithm

The mandatory implementation follows a buffered accumulation strategy.

1. Keep unread data in a static string between function calls.
2. Read `BUFFER_SIZE` bytes from the file descriptor.
3. Append the newly read data to the accumulated data.
4. Stop reading as soon as a newline (`\n`) is found or EOF is reached.
5. Extract the next complete line.
6. Store only the remaining unread data for the next call.
7. Return the extracted line.

### Why this algorithm?

This approach was chosen because it:

- Reads only the necessary amount of data.
- Preserves unread bytes between calls.
- Works with any valid `BUFFER_SIZE`.
- Keeps the implementation simple and suitable for the mandatory part.

---

## Project Structure

```text
get_next_line.c
    Main function and reading workflow

get_next_line_utils.c
    Helper functions for string manipulation

get_next_line.h
    Prototypes, includes and BUFFER_SIZE definition
```

---

## Instructions

Compile with any desired buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<value> \
get_next_line.c \
get_next_line_utils.c
```

Examples:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c
```

If `BUFFER_SIZE` is not defined during compilation, the default value from `get_next_line.h` will be used.

---

## Memory Management

- The static buffer stores only unread data.
- Every dynamically allocated block is released when no longer needed.
- Returned lines become the caller's responsibility.
- Memory is released on read errors before returning `NULL`.

---

## Limitations

This repository contains only the **mandatory** implementation.

The bonus version (multiple file descriptors using a single static variable) is not included.

---

## Resources

### Documentation

- 42 Intranet
- `man 2 read`
- The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
- Linux man-pages

### AI Usage

Artificial Intelligence was used only as a learning and mentoring tool.

It was used to:

- review the project architecture;
- discuss memory management;
- clarify C language concepts;
- review algorithms and edge cases.

No project implementation was generated automatically. The final code was written and understood by the author.
