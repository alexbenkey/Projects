#include "libft.h"

// Add node to beginning of linkedlist
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
