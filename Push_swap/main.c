/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 14:42:08 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 15:10:21 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	main(int argc, char **argv)
{
	t_top_vals	*top;

	if (argc > 1)
	{
		top = initializer(argc, argv);
		if (top)
		{
			sorting_algo(argc, top);
			exit(1);
		}
	}
	else
		exit(255);
}

int	input_checker(t_top_vals *top)

{
	t_alist	*tmp_a;

	tmp_a = top->top_a;
	if (check_duplicates(tmp_a))
	{
		write(2, "Error\n", 6);
		exit (255);
	}
	else if (check_sorted(tmp_a))
	{
		return (0);
	}
	return (1);
}

int	check_for_numbers(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	if (!argv)
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			return (0);
		i++;
	}	
	i = 1;
	while (i < argc)
	{
		x = ps_atoi(argv[i]);
		i++;
	}
	return (1);
}

void	init_top(t_alist *stack_a, t_alist *stack_b, t_top_vals **top)
{
	(*top)->top_a = stack_a;
	(*top)->top_b = stack_b;
}
