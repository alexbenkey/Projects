#include "libft.h"

//takes the number of elements (nelem) and an element size (elsize) 
//returns a void pointer to a memory block with all bytes set to 0
void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;

	str = (char *)malloc(elsize * nelem);
	if (str == 0)
		return (NULL);
	ft_bzero(str, (elsize * nelem));
	return (str);
}
