[![en](https://img.shields.io/badge/lang-en-purple.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-pink.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.fr.md)

# Project: Get Next Line

## 🏁 Goal 🏁
Developing a function that allows us to read a text file referenced by the file descriptor, one line at a time, through successive calls to this function.

## 🚀 Usage 🚀

```shell
git clone git@github.com:nfauconn/get_next_line.git
cd get_next_line/Project
```

Files are located in `test_files/`

```shell
> cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
> ./a.out <file>
```

#### Bonus (multiple fds)

```shell
> cc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=<size>
> ./a.out <file1> <file2> <file3> <...>
```

## 💡 Learning 💡

### 🌐 Language: C 🌐

- **Static Variables:** preserve state information across multiple function calls.

### 🔧 Development Practices and Tools 🔧

- **File Descriptor Management:** efficiently and safely read data from a file descriptor.

- **Memory Management:** careful memory allocation and deallocation to avoid memory leaks and ensure proper memory hygiene.

- **Buffer Management:** effectively read and process data stored in a buffer.

- **Adherence to Norms and Coding Standards:** write code that is not only operational but also streamlined, readable, and in strict adherence to both the project's guidelines and the school's high coding standards
  > *max 5 functions per file, max 25 lines per function, max 80 col per line*

## 📋 Subject 📋

Solo project

## Requirements and Rules

### Language and Standards
- The project must be written in C.
- It must adhere to the coding Norm of 42. Any deviation will result in a score of 0.
- The functions must not quit unexpectedly (segmentation fault, bus error, double free, etc.), except in the case of undefined behavior.

### Memory Management
- All allocated memory on the heap must be freed when necessary. No memory leaks will be tolerated.

### Compilation and Execution
- The program must compile using the flags `-Wall`, `-Wextra`, and `-Werror` and with the option: `-D BUFFER_SIZE=n`. This macro, defined at the time of compiler invocation, will be used to specify the buffer size during the calls to `read()` in our `get_next_line()` function.
- The BUFFER_SIZE value will be modified during peer evaluation and by the Moulinette (the evaluating program of 42) for testing purposes.
- The compilation command will be similar to: 
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>
```

### Functionality
- `get_next_line`:
  - Prototype: `char *get_next_line(int fd);`
  - Files: `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
  - Parameters: `fd`: the file descriptor to read from
  - Return Value: 
    - The content of the line read: correct behavior
    - `NULL`: nothing else to read or an error occurred
  - External Functions Allowed: `read`, `malloc`, `free`

- The function must behave correctly whether it reads from a file or from the standard input.
 
- It must return the line that has been read followed by a `\n`, except when the end of the file has been reached (line returned as it is).

- `get_next_line()` has undefined behavior if, between two calls, the file pointed to by the file descriptor has been modified while the file has not been completely read.
- Reading from a binary file is considered to have undefined behavior.

### What’s Not Allowed
- `libft` is not allowed for this project.
- The function `lseek()` is forbidden.
- Global variables are forbidden.

## Bonus Part

- Implement `get_next_line()` with only one static variable.
- Extend `get_next_line()` to handle multiple file descriptors. For instance, if file descriptors 3, 4, and 5 are accessible for reading, it should be possible to read them turn by turn without ever losing the read contents on each of the file descriptors and without returning the wrong line.

Add the suffix `_bonus.[c/h]` to the files of this part. In addition to the 3 mandatory files, submit the following files:
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`
