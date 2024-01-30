[![en](https://img.shields.io/badge/lang-en-purple.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-pink.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.fr.md)

# Get Next Line

A function that reads a text file referenced by the file descriptor, one line at a time, through successive calls to this function.
  
External Functions Allowed: `read`, `malloc`, `free`. No global variables allowed.

## Usage

```shell
git clone git@github.com:nfauconn/get_next_line.git
cd get_next_line/Project
```

  - Files: `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
  - Return Value: 
    - The content of the line read, followed by a '\n', except when the end of the file has been reached (line returned as it is): correct behavior
    - `NULL`: nothing else to read or an error occurred

- `get_next_line()` has undefined behavior if, between two calls, the file pointed to by the file descriptor has been modified while the file has not been completely read.
- Reading from a binary file is considered to have undefined behavior.

Files are located in `test_files/`

```shell
> cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 main.c get_next_line.c get_next_line_utils.c 
> ./a.out <file>
```
 Feel free to test different BUFFER_SIZE values.

#### Usage with multiple fds

```shell
> cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c 
> ./a.out <file1> <file2> <file3> <...>
```

## Specific skills

- **Static Variables:** preserve state information across multiple function calls.

- **File Descriptor Management:** efficiently and safely read data from file descriptors.

- **Buffer Management:** effectively read and process data stored in a buffer.

- **Error Management:** comprehensive error checking and response mechanisms, ensuring the program behaves predictably under various scenarios.

- **Low-Level Programming Proficiency:** memory, pointers, and system calls at a low level.

- **Adherence to Norms and Coding Standards:** write code that is not only operational but also streamlined, readable, and in strict adherence to both the project's guidelines and the school's high coding standards
