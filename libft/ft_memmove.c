/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:52:53 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/15 19:34:06 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;

	i = 0;
	c_dest = (char *) dst;
	c_src = (char *) src;
	if (c_dest == c_src || n == 0)
		return (c_dest);
	if (dst < src)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	else
		while (n--)
			c_dest[n] = c_src[n];
	return (c_dest);
}
