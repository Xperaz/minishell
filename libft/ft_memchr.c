/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:53:54 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/15 19:28:51 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*c_s;
	unsigned char	c_c;
	size_t			i;

	if (n == 0)
		return (0);
	c_s = (unsigned char *) s;
	c_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (c_s[i] == c_c)
		{
			return (&c_s[i]);
		}
		i++;
	}
	return (0);
}
