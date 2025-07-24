/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 21:41:55 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 15:59:36 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	small_sort(t_top_vals *top, int vals)
{
	if (vals == 3)
		rotate_a(top);
	else if (vals == 4)
		sort_3(top->top_a, top);
	else if (vals == 5)
		sort_4(top);
	else if (vals == 6)
		sort_5(top);
}

void	sort_3(t_alist *tmp, t_top_vals *top)
{
	if (tmp->index < tmp->next->index && tmp->index < tmp->next->next->index)
	{
		push_b(top);
		rotate_a(top);
		push_a(top);
	}
	else if (tmp->index > tmp->next->index && \
	tmp->index > tmp->next->next->index)
	{
		if (tmp->next->index > tmp->next->next->index)
		{
			rotate_a(top);
			swap_a(top);
		}
		else
			rotate_a(top);
	}
	else
	{
		if (tmp->next->index > tmp->index)
			reverse_rotate_a(top);
		else
			swap_a(top);
	}
}

void	sort_4(t_top_vals *top)
{
	int		place;
	t_alist	*tmp;

	tmp = top->top_a;
	place = find_index(top, 0);
	if (place == 3)
		reverse_rotate_a(top);
	else if (place >= 0 && place <= 2)
	{
		while (top->top_a->index != 0)
			rotate_a(top);
	}
	push_b(top);
	if (!check_sorted(top->top_a))
		sort_3(top->top_a, top);
	push_a(top);
}

void	sort_5(t_top_vals *top)
{
	t_alist	*tmp;
	int		index;

	index = 0;
	tmp = top->top_a;
	while (tmp && (index <= 1))
	{
		if (top->top_a->index == 0 || top->top_a->index == 1)
		{
			push_b(top);
			index++;
		}
		else
			rotate_a(top);
	}
	if (!check_sorted(top->top_a))
		sort_3(top->top_a, top);
	if (check_sorted(top->top_b))
		rotate_b(top);
	push_a(top);
	push_a(top);
}
