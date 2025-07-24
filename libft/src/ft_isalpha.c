#include "libft.h"

//returns non-null value if input value is an alphabetical character
int	ft_isalpha(int input)
{
	return ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'));
}
