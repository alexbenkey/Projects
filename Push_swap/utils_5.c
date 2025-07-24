/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_5.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 22:43:59 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 16:01:20 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_alist	*get_stack(t_top_vals *top, char stack)
{
	if (stack == 'a')
		return (top->top_a);
	else if (stack == 'b')
		return (top->top_b);
	else
		return (NULL);
}

void	set_stack(t_top_vals *top, t_alist *lst, char stack)
{
	if (stack == 'a')
		top->top_a = lst;
	else if (stack == 'b')
		top->top_b = lst;
}

// find the current place of a given index number in stack_a. 
// returns the place the stack (0 for first), -1 if it cannot be found.
int	find_index(t_top_vals *top, int index)
{
	t_alist	*tmp;
	int		i;

	i = 0;
	tmp = top->top_a;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	error_exit(void)
{
	write (2, "Error\n", 6);
	exit (255);
}
