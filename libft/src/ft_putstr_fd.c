#include "libft.h"

// Outputs an integer value to the stream with the given file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
	{
		write(fd, s, ft_strlen(s));
	}
}
