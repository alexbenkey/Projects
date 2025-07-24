#include "libft.h"

//writes character 'c' to stream with file discriptor 'fd'
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
