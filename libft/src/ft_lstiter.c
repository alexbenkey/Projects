#include "libft.h"

// Apply function (*f) to the content of each node of a linkedlist
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*following;

	current = lst;
	while (current)
	{
		following = current->next;
		f(current->content);
		current = following;
	}
}
