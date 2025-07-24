 #include "libft.h"

// Returns a pointer to a new linkedlist with 't_list' nodes
t_list	*ft_lstnew(void	*content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = content;
		tmp->next = 0;
	}
	return (tmp);
}
