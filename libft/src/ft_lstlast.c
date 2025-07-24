#include "libft.h"

// Returns a pointer to the last node in a linkedlist
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		if (current->next == NULL)
			return (current);
		current = current->next;
	}
	return (lst);
}
