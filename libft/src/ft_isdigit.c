#include "libft.h"

// returns a truthy value if input is an ascii number value
int	ft_isdigit(int input)
{
	return (input >= '0' && input <= '9');
}
