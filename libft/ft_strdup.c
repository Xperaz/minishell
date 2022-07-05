/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:50:55 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/03 22:52:35 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = NULL;
	i = ft_strlen(src);
	ptr = malloc(i * sizeof(char) + 1);
	if (ptr)
	{
		i = 0;
		while (src[i] != '\0')
		{
			ptr[j++] = src[i++];
		}
		ptr[j] = ('\0');
	}
	return (ptr);
}
