/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 13:59:42 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/03 16:12:58 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_alist	*ps_lstnew(int content)
{
	t_alist	*tmp;

	tmp = malloc(sizeof(t_alist));
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}

void	ps_lstadd_back(t_alist *lst, t_alist *new)
{
	t_alist	*current;
	t_alist	*tmp;

	current = lst;
	if (lst == 0)
		return ;
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
	tmp = current;
	current = current->next;
	current->prev = tmp;
}

t_alist	*ps_lstadd_front(t_alist *lst, t_alist *new)
{
	t_alist	*current;

	current = NULL;
	if (!lst)
	{	
		lst = new;
		lst->next = NULL;
		lst->prev = NULL;
		return (lst);
	}
	if (lst)
	{
		current = new;
		current->next = lst;
		current->prev = 0;
		lst->prev = current;
	}
	return (current);
}

int	count_nodes(t_alist *a_list)
{
	t_alist	*current;
	int		i;

	if (!a_list)
		return (0);
	current = a_list;
	i = 0;
	while (current->next != 0)
	{
		i++;
		current = current->next;
	}
	return (i + 1);
}

t_alist	*init_stack_a(int argc, char **values)
{
	int			i;
	int			conv;
	t_alist		*stack_a;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		conv = ft_atoi(values[i]);
		if (values[i] && !stack_a)
			stack_a = ps_lstnew(conv);
		else if (values[i] && stack_a)
			ps_lstadd_back(stack_a, ps_lstnew(conv));
		i++;
	}
	return (stack_a);
}
