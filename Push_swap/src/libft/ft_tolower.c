/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:02:47 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 17:02:48 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int input)
{	
	if (input >= 65 && input <= 90)
		return (input + 32);
	else
		return (input);
}
