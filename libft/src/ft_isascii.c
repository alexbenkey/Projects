#include "libft.h"

// returns a truthy value if input is an ascii value
int	ft_isascii(unsigned int input)
{
	return (input >= 0 && input <= 127);
}
