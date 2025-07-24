/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_rules_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 21:43:47 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/01 21:47:47 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	swap_a(t_top_vals *top)
{
	swap(top, 'a');
	write(1, "sa\n", 3);
}

void	swap_b(t_top_vals *top)
{
	swap(top, 'b');
	write(1, "sb\n", 3);
}

void	reverse_rotate_a(t_top_vals *top)
{
	reverse_rotate(top, 'a');
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_top_vals *top)
{
	reverse_rotate(top, 'b');
	write(1, "rrb\n", 4);
}

void	push(t_top_vals *top, char stack)
{
	if (stack == 'a')
		push_a(top);
	if (stack == 'b')
		push_b(top);
}
