[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.md)

# Project: Get Next Line

## 🏁 Goal 🏁
Developing a function that allows us to read a text file referenced by the file descriptor, one line at a time, through successive calls to this function.

## 💡 Learning 💡

### 🌐 Language: C 🌐

- **Static Variables:** The project introduced me to the concept and utility of static variables in C, showing me how they can preserve state information across multiple function calls.


### 🔧 Development Practices and Tools 🔧

- **File Descriptor Management:** It allowed me to deepen my understanding of file descriptors and their manipulation in C, teaching me how to efficiently and safely read data from a file descriptor.

- **Memory Management:** The project enhanced my ability to manage memory dynamically. It taught me the importance of careful memory allocation and deallocation to avoid memory leaks and ensure proper memory hygiene.

- **Buffer Management:** It provided me with practical experience in managing buffers, including how to effectively read and process data stored in a buffer.

- **Code Organization and Modularization:** It taught me how to organize my code into separate, modular files, enhancing maintainability and readability.

- **Working with Compilers and Makefiles:** It expanded my understanding of the compilation process, including the use of compiler flags and Makefiles, thus streamlining the build process of my projects.

- **Adherence to Norms and Coding Standards:** The project underscored the significance of writing not just functional but also clean and concise code. By enforcing a subject-specific constraint of a maximum of two files, and aligning with the school's rigorous coding norms—limiting each file to no more than five functions and each function to a maximum of 25 lines of 80 columns—it emphasized the necessity of brevity and clarity in coding. This structured approach, balancing project requirements and school norms, compelled me to write code that is not only operational but also streamlined, readable, and in strict adherence to both the project's guidelines and the school's high coding standards.

- **Peer Code Review and Testing:** As all projects in 42, it exposed me to the practice of code review and testing, improving my ability to critically analyze both my code and that of my peers, and fostering a mindset of continuous improvement and refinement.

## 📋 Subject 📋

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
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
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

```c
#include "get_next_line_bonus.h"

static char	*nl_chr(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

static char	*all(char **buf, char **rest)
{
	*buf = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (NULL);
	if (!*rest)
	{
		*rest = ft_strdup("");
		if (!*rest)
		{
			free(*buf);
			return (NULL);
		}
	}
	return (*rest);
}

static char	*fill_rest(char **rest, t_newstr *line)
{
	t_newstr	newrest;

	newrest.len = ft_strlen(*rest) - line->len;
	newrest.str = ft_substr(*rest, line->len + 1, newrest.len);
	if (!newrest.str)
		free(line->str);
	return (free_replace(rest, newrest.str));
}

static char	*fill_line(char **rest, char *nl_ptr)
{
	t_newstr	line;

	line.str = NULL;
	if (nl_ptr)
	{
		line.len = nl_ptr - *rest;
		line.str = ft_substr(*rest, 0, line.len + 1);
		if (!line.str)
			return (free_replace(rest, NULL));
		fill_rest(rest, &line);
		if (!rest)
			return (NULL);
	}
	else
	{
		line.str = ft_strdup(*rest);
		free_replace(rest, NULL);
		if (!line.str)
			return (NULL);
	}
	return (line.str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rest[PATH_MAX];
	char		*nl_ptr;
	ssize_t		ret;

	nl_ptr = NULL;
	ret = 1;
	while (ret && !nl_ptr)
	{
		if (fd < 0 || fd > PATH_MAX || BUFFER_SIZE < 1 || !all(&buf, &rest[fd]))
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0 || (ret == 0 && !*rest[fd]))
		{
			free(buf);
			return (free_replace(&rest[fd], NULL));
		}
		buf[ret] = '\0';
		free_replace(&rest[fd], ft_strjoin(rest[fd], buf));
		free(buf);
		if (!rest[fd])
			return (NULL);
		nl_ptr = nl_chr(rest[fd]);
	}
	return (fill_line(&rest[fd], nl_ptr));
}
```