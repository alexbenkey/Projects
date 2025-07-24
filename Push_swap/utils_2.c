/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 22:24:00 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 16:16:56 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_alist	*init_stack_b(void)
{
	t_alist		*stack_b;

	stack_b = ps_lstnew(0);
	return (stack_b);
}

static int	p_check(const char *str)
{
	int	i;
	int	p;

	p = 1;
	i = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	if (!ft_isdigit(*str))
		error_exit();
	return (p);
}

int	ps_atoi(const char *str)
{
	int		i;
	int		p;
	long	val;

	i = 0;
	val = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	p = p_check(str);
	if (*str == '-' || *str == '+')
		str++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		val *= 10;
		val += (str[i] - 48);
		i++;
		if (val * p < INT_MIN || val * p > INT_MAX)
			error_exit();
	}
	if (str[i] != '\0')
		error_exit();
	return (val * p);
}
