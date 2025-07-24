/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:02:41 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 17:02:42 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*btemp;
	int		i;

	btemp = (char *)s;
	i = 0;
	while (s[i] != 0)
		i++;
	while (i >= 0)
	{	
		if (s[i] == (unsigned char)c)
			return (&btemp[i]);
		i--;
	}
	return (0);
}
