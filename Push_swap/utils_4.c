/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 22:43:02 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 15:57:04 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	return_next_smallest(t_top_vals *top, char sign, int prev)
{
	t_alist	*lst;
	int		current;

	if (sign == 'a')
		lst = top->top_a;
	if (sign == 'b')
		lst = top->top_b;
	current = return_largest_in_stack(top, 'a');
	while (lst->next)
	{
		if ((prev < lst->content) && (current > lst->content))
			current = lst->content;
		lst = lst->next;
	}
	if ((prev < lst->content) && (current > lst->content))
		current = lst->content;
	return (current);
}

int	return_largest_in_stack(t_top_vals *top, char sign)
{
	t_alist	*lst;
	int		largest;

	if (sign == 'a')
		lst = top->top_a;
	if (sign == 'b')
		lst = top->top_b;
	largest = lst->content;
	while (lst->next)
	{
		lst = lst->next;
		if (largest < lst->content)
			largest = lst->content;
	}
	if (largest < lst->content)
		largest = lst->content;
	return (largest);
}

// sets the index of all of the nodes in stack A,
// depending on the relative size of the content. 
void	index_increasing(t_top_vals *top)
{
	int		i;
	int		count;
	int		min;
	t_alist	*temp;

	i = 0;
	count = count_nodes(top->top_a);
	min = return_smallest_in_stack(top, 'a');
	temp = find_node(top, 'a', min);
	temp->index = i;
	i++;
	while (i < (count))
	{
		min = return_next_smallest(top, 'a', min);
		temp = find_node(top, 'a', min);
		temp->index = i;
		i++;
	}
}

// returns the node with the specified content 'val'
t_alist	*find_node(t_top_vals *top, char stack, int val)
{
	t_alist	*current;

	if (stack == 'a')
		current = top->top_a;
	if (stack == 'b')
		current = top->top_b;
	while (current->next)
	{
		if (current->content == val)
			return (current);
		current = current->next;
	}
	if (current->content == val)
		return (current);
	else
		return (NULL);
}

t_top_vals	*initializer(int argc, char **argv)
{
	t_top_vals	*top;

	top = ft_calloc(sizeof(t_top_vals), 1);
	if (!check_for_numbers(argc, argv))
	{
		write(2, "Error\n", 6);
		free(top);
		exit (255);
		return ((void *)0);
	}
	top->top_a = init_stack_a(argc, argv);
	top->top_b = NULL;
	top->list_size = (argc - 1);
	if (!input_checker(top))
		return (NULL);
	index_increasing(top);
	return (top);
}
