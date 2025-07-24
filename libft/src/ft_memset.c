#include "libft.h"

// Writes 'len' bytes of value c (converted to an unsigned char) to the string 'mystring'.
void	*ft_memset(char	*mystring, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		mystring[i] = (unsigned char)c;
		i++;
	}
	return (mystring);
}
