/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:54:06 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/15 19:35:19 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (a);
}
