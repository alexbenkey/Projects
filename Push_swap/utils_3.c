/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 22:41:54 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/03 16:30:51 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	check_sorted(t_alist *lst_a)
{
	t_alist	*temp;

	temp = lst_a;
	while (temp->next)
	{
		if (temp->next->content < temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_duplicates(t_alist *lst)
{
	while (lst->next)
	{
		if (check_rest_of_list(lst->content, lst))
			return (1);
		lst = lst->next;
	}
	return (0);
}

// checks if there is a node with val 'i' somewhere in the list.
int	check_rest_of_list(int i, t_alist *lst)
{
	t_alist	*current;

	current = lst;
	while (current->next)
	{
		current = current->next;
		if (current->content == i)
			return (1);
	}
	return (0);
}

int	check_if_smallest(t_alist *stack_a, int ref)
{
	t_alist	*temp;

	temp = stack_a;
	while (temp->next)
	{
		temp = temp->next;
		if (ref > temp->content)
			return (0);
	}
	return (1);
}

//returns the smallest integer in either of the stacks.
//takes "top" and either 'a' or 'b' 
// depending on which stack you want to search through 

int	return_smallest_in_stack(t_top_vals *top, char sign)
{
	t_alist	*lst;
	int		smallest;

	if (sign == 'a')
		lst = top->top_a;
	if (sign == 'b')
		lst = top->top_b;
	smallest = lst->content;
	while (lst->next)
	{
		lst = lst->next;
		if (smallest > lst->content)
			smallest = lst->content;
	}
	if (smallest > lst->content)
		smallest = lst->content;
	return (smallest);
}
