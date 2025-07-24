#include "libft.h"

// Delete all content of a given node in linkedlist (lst)
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
