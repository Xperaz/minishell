/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:55:05 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/16 14:05:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*ptr;

	j = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (len >= ft_strlen(s))
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (j < len && s[start] != '\0')
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}
