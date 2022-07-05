/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:54:46 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/16 13:59:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (len == 0 && needle[i] != '\0')
		return (NULL);
	if (needle[i] == '\0' || len == '\0')
		return ((char *)haystack);
	if (len == 1 && haystack[0] == needle[0])
		return ((char *)haystack);
	while (i < len - 1 && haystack[i])
	{
		j = 0;
		while ((haystack[i + j] == needle[j] || needle[j] == '\0'))
		{
			if (needle[j] == '\0' && i + j <= len)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
