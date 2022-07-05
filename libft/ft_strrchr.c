/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:56:20 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/15 20:19:15 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	a;
	char	*b;

	i = ft_strlen(s);
	a = (char)c;
	b = (char *)s;
	while (i >= 0)
	{
		if (b[i] == a)
			return (&b[i]);
		else if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
