/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_rules.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 21:51:04 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/06 15:59:01 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	rotate_both(t_top_vals *top)
{
	rotate_a(top);
	rotate_b(top);
}

int	reverse_rotate(t_top_vals *top, char stack)
{
	t_alist	*first;
	t_alist	*tmp;

	first = get_stack(top, stack);
	tmp = first;
	if (count_nodes(tmp) > 1)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		first->prev = tmp;
		tmp->next = first;
		set_stack(top, tmp, stack);
		return (1);
	}
	return (0);
}

int	reverse_rotate_both(t_top_vals *top)
{
	if (reverse_rotate(top, 'a') && reverse_rotate(top, 'b'))
	{
		write(1, "rrr", 1);
		return (1);
	}
	return (0);
}

void	rotate_a(t_top_vals *top)
{
	rotate(top, 'a');
	write(1, "ra\n", 3);
}

void	rotate_b(t_top_vals *top)
{
	rotate(top, 'b');
	write(1, "rb\n", 3);
}
