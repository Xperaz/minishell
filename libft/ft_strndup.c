/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:26:03 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 02:29:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = NULL;
	ptr = malloc(n * sizeof(char) + 1);
	if (ptr)
	{
		i = 0;
		while (i < n)
		{
			ptr[j++] = src[i++];
		}
		ptr[j] = ('\0');
	}
	return (ptr);
}
