[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.md)

# Project: Get Next Line

## 🏁 Goal 🏁
Developing a function that allows us to read a text file referenced by the file descriptor, one line at a time, through successive calls to this function.

## 💡 Learning 💡

### 🌐 Language: C 🌐
  - **A**:
    - U

### 🔧 Development Practices and Tools 🔧
- **M**:
  - U.

## 📋 Subject 📋

## Introduction
Get Next Line is a project aimed at , enriching your collection with a very practical function while introducing you to a surprising element of C programming: static variables.

## Objectives
The goal is to allow you to . This project will not only test your skills in handling file descriptors and memory but also assess your ability to optimize your code for performance, especially in terms of memory usage.

## Requirements and Rules

### Language and Standards
- Your project must be written in C.
- You must adhere to the Norm. Any deviation will result in a score of 0.
- Your functions must not quit unexpectedly (segmentation fault, bus error, double free, etc.), except in the case of undefined behavior.

### Memory Management
- All allocated memory on the heap must be freed when necessary. No memory leaks will be tolerated.
- If the project requires it, you must submit a Makefile that compiles your sources into the expected output using the flags `-Wall`, `-Wextra`, and `-Werror`. Your Makefile must not relink.

### Compilation and Execution
- Your program must compile with the option: `-D BUFFER_SIZE=n`. This macro, defined at the time of compiler invocation, will be used to specify the buffer size during your calls to `read()` in your `get_next_line()` function.
- The BUFFER_SIZE value will be modified during peer evaluation and by the Moulinette for testing purposes.
- The compilation command will be similar to: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`.

### Functionality
- `get_next_line`:
  - Prototype: `char *get_next_line(int fd);`
  - Files: `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
  - Parameters: `fd`: the file descriptor to read from
  - Return Value: The content of the line read: correct behavior, `NULL`: nothing else to read or an error occurred
  - External Functions Allowed: `read`, `malloc`, `free`

Ensure that your function behaves correctly whether it reads from a file or from the standard input. It is important to always return the line that has been read followed by a newline `\n`, except when you have reached the end of the file, and it does not end with a `\n`.

The header file `get_next_line.h` must contain at least the prototype of the function. You can add additional necessary functions in `get_next_line_utils.c`.

### Constraints
- `get_next_line()` has undefined behavior if, between two calls, the file pointed to by the file descriptor has been modified while the file has not been completely read.
- Reading from a binary file is considered to have undefined behavior, although you can choose to handle this consistently.

### What’s Not Allowed
- `libft` is not allowed for this project.
- The function `lseek()` is forbidden.
- Global variables are forbidden.

## Bonus Part
Due to its simplicity, the Get Next Line project leaves little room for bonuses, but your creativity is always encouraged. If you have successfully completed the mandatory part, feel free to attempt the bonuses to push your limits further.

### Bonuses to implement:
- Implement `get_next_line()` with only one static variable.
- Extend `get_next_line()` to handle multiple file descriptors. For instance, if file descriptors 3, 4, and 5 are accessible for reading, it should be possible to read them turn by turn without ever losing the read contents on each of the file descriptors and without returning the wrong line.

Add the suffix `_bonus.[c/h]` to the files of this part. In addition to the 3 mandatory files, you will submit the following files:
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

Bonuses will only be evaluated if the mandatory part is PERFECT. By perfect, we mean complete and without any malfunction. If you have not succeeded in ALL the points of the mandatory part, your bonus part will not be taken into account.

## Submission and Peer Evaluation
Submit your work on your Git repository as usual. Only the work present on your repository will be evaluated in defense. Make sure that the names of your folders and files are in accordance with the subject's requests.

For your tests, keep in mind that:
1) The buffer and the line can be of very different sizes.
2) A file descriptor does not only point to simple files.

Be smart and verify your work with your peers. Prepare a wide range of tests for your evaluation.

Once you have validated this project, feel free to add your `get_next_line()` to your libft.

## Resources and Documentation
- [libc Manuals](https://linux.die.net/man/)
- [Static Variables in C](https://www.tutorialspoint.com/cprogramming/c_storage_classes.htm)

---
