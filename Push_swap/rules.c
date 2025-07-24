/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 18:40:09 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/06 13:59:03 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	swap(t_top_vals *top, char stack)
{
	t_alist	*tmp;
	t_alist	*lst;

	lst = NULL;
	if (stack == 'a')
		tmp = top->top_a;
	if (stack == 'b')
		tmp = top->top_b;
	if (count_nodes(tmp) > 1)
	{
		lst = tmp->next;
		lst->prev = NULL;
		tmp->next = lst->next;
		tmp->next->prev = tmp;
		lst->next = tmp;
		tmp->prev = lst;
	}
	if (stack == 'a')
		top->top_a = lst;
	if (stack == 'b')
		top->top_b = lst;
	return (0);
}

int	swap_both(t_top_vals *top)
{
	if (swap(top, 'a') && swap(top, 'b'))
		return (1);
	return (0);
}

int	push_b(t_top_vals *top)
{
	t_alist	*tmp;

	tmp = top->top_a;
	if (!top->top_a)
		return (0);
	else if (top->top_a && top->top_a->next)
	{
		top->top_a = top->top_a->next;
		top->top_b = ps_lstadd_front(top->top_b, tmp);
	}
	else if (!top->top_a->next)
	{
		top->top_a = NULL;
		top->top_b = ps_lstadd_front(top->top_b, tmp);
	}
	write(1, "pb\n", 3);
	return (1);
}

int	push_a(t_top_vals *top)
{
	t_alist	*tmp;

	tmp = top->top_b;
	if (!top->top_b)
		return (0);
	else if (top->top_b && top->top_b->next)
	{
		top->top_b = top->top_b->next;
		top->top_a = ps_lstadd_front(top->top_a, tmp);
	}
	else if (!top->top_b->next)
	{
		top->top_b = NULL;
		top->top_a = ps_lstadd_front(top->top_a, tmp);
	}
	write(1, "pa\n", 3);
	return (1);
}

void	rotate(t_top_vals	*top, char stack)
{
	t_alist	*lst;
	t_alist	*temp;
	t_alist	*top_node;

	lst = get_stack(top, stack);
	temp = lst;
	lst = lst->next;
	top_node = lst;
	top_node->prev = 0;
	while (lst->next)
		lst = lst->next;
	lst->next = temp;
	temp->prev = lst;
	temp->next = 0;
	set_stack(top, top_node, stack);
}
