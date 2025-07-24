#include "libft.h"

// returns a truthy value if input is a printable
int	ft_isprint(unsigned int input)
{
	if (input >= 32 && input <= 126)
		return (1);
	else
		return (0);
}
