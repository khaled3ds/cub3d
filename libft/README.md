# C Standard Library Rebuild

## Overview

This project is a ground-up reimplementation of essential functions from the C standard library.

The objective is to reproduce core libc behavior while gaining a deep understanding of:

- Memory manipulation
- String processing
- Linked list structures
- Pointer arithmetic
- Defensive programming in C

All functions are implemented without relying on the standard library equivalents.

---

## Why Rebuild the Standard Library?

Reimplementing libc functions exposes:

- How low-level memory operations work
- How undefined behavior can occur
- The importance of boundary checks
- Manual memory ownership responsibility
- API design discipline

This project builds a foundational layer used in larger systems projects.

---

## Implemented Modules

### Memory Functions
- `memset`
- `bzero`
- `memcpy`
- `memmove`
- `memchr`
- `memcmp`
- `calloc`

### String Functions
- `strlen`
- `strlcpy`
- `strlcat`
- `strchr`
- `strrchr`
- `strncmp`
- `strnstr`
- `strdup`

### Character Classification
- `isalpha`
- `isdigit`
- `isalnum`
- `isascii`
- `isprint`
- `toupper`
- `tolower`

### String Manipulation Utilities
- `substr`
- `strjoin`
- `strtrim`
- `split`
- `itoa`
- `strmapi`
- `striteri`

### File Descriptor Output
- `putchar_fd`
- `putstr_fd`
- `putendl_fd`
- `putnbr_fd`

### Linked List Implementation
- `lstnew`
- `lstadd_front`
- `lstadd_back`
- `lstsize`
- `lstlast`
- `lstdelone`
- `lstclear`
- `lstiter`
- `lstmap`

---

## Design Principles

- Strict adherence to original libc behavior
- Manual memory management
- Clear ownership rules
- NULL safety checks
- No hidden allocations
- Predictable return values

---

## Compilation

```
make
```

This produces:

```
libft.a
```

A static library that can be linked into other projects.

---

## Usage Example

```
gcc main.c -L. -lft -o program
```

---

## Memory Safety

- All allocations checked for NULL
- No global state
- Linked list functions safely handle empty lists
- No memory leaks in normal usage

---

## Architecture

The library is modular:

- Header file exposing public API
- Static archive (.a) build
- Source files grouped by functionality
- Strict function prototypes

---

## What This Project Demonstrates

This implementation reflects:

- Strong pointer control
- Deep understanding of memory layout
- Manual resource management
- API recreation under constraints
- Systems-level C programming discipline

This library serves as a foundational dependency for larger projects such as:

- Shell implementations
- Networking tools
- Sorting engines
- File processing systems

---

## Future Improvements

- Unit testing framework
- Benchmark comparison with libc
- Safer string API variants
- Optional debug instrumentation

---

## Author

Khaled Adas  
Systems Programming | C | Low-Level Architecture
