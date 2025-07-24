#include "libft.h"

// Compares byte string s1 against byte string s2.  Both strings are assumed to be n bytes long.
// Returns zero if the two strings are identical, otherwise returns the difference between the first two differing bytes
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*s1_temp;
	unsigned char		*s2_temp;
	size_t				i;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((s1_temp[i]) != (s2_temp[i]))
			return ((s1_temp[i]) - (s2_temp[i]));
		i++;
	}
	return (0);
}
