#include "libft.h"

// outputs string 's' to output with given file descriptor(fd)
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s != 0)
	{
		i = 0;
		while (s[i])
		{
			if (ft_isascii(s[i]))
				write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
