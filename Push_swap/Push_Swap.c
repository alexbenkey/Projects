/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 17:05:17 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/06 16:00:36 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ray_dicks_sort(t_top_vals *top)
{
	int		size;
	int		max_num;
	int		max_bits;
	int		i;

	i = 0;
	size = count_nodes(top->top_a);
	max_num = (size - 1);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		ray_dicks_core(top, i);
		while (top->top_b)
			push_a(top);
		++i;
	}
}

void	ray_dicks_core(t_top_vals *top, int i)
{
	int	j;
	int	size;
	int	num;

	j = 0;
	size = count_nodes(top->top_a);
	while (j < size)
	{
		num = top->top_a->index;
		if (((num >> i) & 1) == 1)
			rotate_a(top);
		else
			push_b(top);
		j++;
	}
}

void	sorting_algo(int argc, t_top_vals *top)
{
	if (argc <= 6)
		small_sort(top, argc);
	else
		ray_dicks_sort(top);
}
