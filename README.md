*This project has been created as part of the 42 curriculum by joacarva.*

# Get Next Line

## Description

Get Next Line is a C programming project developed as part of the 42 curriculum.

The goal is to implement a function that reads and returns one line at a time from a file descriptor.

The project focuses on file handling, memory management, static variables, and understanding how the `read()` system call works.

The function has the following prototype:

```c
char *get_next_line(int fd);
```

Each call returns the next available line, including the newline character (`\n`) when present. When there is nothing left to read or an error occurs, the function returns `NULL`.

## Instructions

### Files

The mandatory part consists of:

- `get_next_line.c` — Main function and reading logic.
- `get_next_line_utils.c` — Helper functions for string manipulation.
- `get_next_line.h` — Function prototypes, includes, and buffer configuration.

### Compilation

Compile the project with a test main function:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Run the executable:

```bash
./gnl
```

`BUFFER_SIZE` controls the maximum number of bytes requested during each `read()` call.

The project supports different buffer sizes and can also be compiled without explicitly defining `BUFFER_SIZE`, using the default value specified in the header file.

### Example

Given a file containing:

```text
Hello World
42 Porto
Get Next Line
```

Successive calls to `get_next_line(fd)` return:

```text
"Hello World\n"
"42 Porto\n"
"Get Next Line\n"
NULL
```

## Algorithm

The implementation uses a static variable to preserve unread data between function calls.

### 1. Reading Data

A buffer is dynamically allocated according to `BUFFER_SIZE`.

The function uses `read()` to retrieve data from the file descriptor. Reading continues until a newline character is found or the end of the file is reached.

### 2. Storing Data

Data retrieved by `read()` is appended to a static string, commonly called `stash`.

This allows the function to preserve characters that were read but do not belong to the current line.

### 3. Extracting a Line

The stored data is examined to find the first newline character.

When a newline is found, the function extracts the characters up to and including `\n`.

If the end of the file is reached without a final newline, the remaining characters are returned as the last line.

### 4. Preserving Remaining Data

After extracting the line, the remaining characters are kept in the static variable for the next function call.

This prevents previously read data from being lost.

### 5. Memory Management

Dynamically allocated memory is managed using `malloc()` and `free()`.

Temporary buffers and strings that are no longer needed must be released to avoid memory leaks.

Read errors and empty files must also be handled correctly.

### Algorithm Justification

A static variable is used because it preserves information between calls without requiring global variables.

Reading data in blocks reduces the need to request individual characters, while retaining unread content ensures that no characters are lost when a buffer contains multiple lines.

This approach supports lines of varying lengths without requiring the entire file to be loaded into memory.

## Resources

### Documentation

- [Linux manual — read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux manual — malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [GNU C Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
- 42 Get Next Line subject, version 14.3.

### AI Usage

AI tools, including ChatGPT, were used as a learning aid to understand the `read()` function, static variables, buffer management, memory allocation, and the purpose of the `stash`.

AI was also used to explain individual programming concepts, review code snippets, suggest debugging approaches, and assist with README documentation.

The project implementation was developed through individual programming and testing.

## Learning Outcomes

This project provides practical experience with:

- File descriptors and low-level file reading.
- Static variables and persistent state.
- Dynamic memory allocation.
- String manipulation.
- Handling end-of-file and read errors.
- Preventing memory leaks.
- Working with configurable buffer sizes.
