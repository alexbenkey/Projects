#include "libft.h"

// Clear all nodes in a linked in using the provided (del) function, set beginning node to 0;
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*following;

	current = *lst;
	while (current)
	{
		following = current->next;
		del(current->content);
		free(current);
		current = following;
	}
	*lst = NULL;
}
