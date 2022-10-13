#include <stdlib.h>
#include <sys/types.h>
#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest = NULL;
	char		*nl_ptr;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nl_ptr = NULL;
	
}
