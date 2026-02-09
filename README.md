# get_next_line 📄

**get_next_line** is a project that allows reading a file line by line from a file descriptor.
It helps understand the following concepts : file I/O, dynamic memory management, and working with buffers.

---

## Table of Contents
1. [Highlights](#highlights)
2. [Functions](#functions)
3. [Definitions](#definitions)
4. [Installation](#installation)

---

## Highlights

- Read a file line by line with a single function
- Handle multiple file descriptors simultaneously
- Manage dynamic memory safely
- Return NULL when the end of file is reached or on error

## Definitions

| Term | Description |
|------|-------------|
| **Line** | A sequence of characters ending with a newline character `\n` or the end of file. |
| **Buffer** | A temporary memory area used to read chunks of data from a file. |
| **File descriptor (fd)** | An integer that uniquely identifies an open file in the operating system. |
| **EOF** | End Of File, a condition indicating that there is no more data to read. |
| **Dynamic memory** | Memory allocated at runtime using `malloc`, which must be freed by the programmer. |

## Functions

**Core Function**

get_next_line(int fd) : Reads the next line from the file descriptor fd and returns it as a string
- Returns NULL at end of file or on error
- Allocates memory dynamically; the caller must free the returned string


## Installation

1. Clone the repository:

```bash
git clone https://github.com/vgalmich/get_next_line.git
cd ft_printf
```

2. Compile the program:
```bash
make
```

3. Clean object files:
```bash
make clean
make fclean
make re
```

---
vgalmich – 42 School Student