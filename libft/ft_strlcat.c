/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:54:20 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/19 22:55:35 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	res = 0;
	while (dest[i])
		i++;
	while (src[res])
		res++;
	if (dstsize <= i)
		res += dstsize;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (res);
}
