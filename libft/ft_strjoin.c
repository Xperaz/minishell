/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:53:09 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/04 00:40:37 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l_s1;
	int		l_s2;
	int		i;
	int		j;
	char	*ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	ptr = (char *) malloc ((l_s1 + l_s2 + 1) * sizeof (char));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < l_s1)
		ptr[i] = s1[i];
	j = -1;
	while (++j < l_s2)
		ptr[i++] = s2[j];
	ptr[i] = '\0';
	return (ptr);
}
