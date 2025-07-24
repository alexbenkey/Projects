/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:29:14 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 01:29:16 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_strlen(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	if (!s)
	{
		ft_putstr_strlen("(null)");
		return (6);
	}
	return (ft_strlen(s));
}
