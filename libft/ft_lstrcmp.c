/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:28:11 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 02:28:23 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstrcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] && c_s2[i])
	{
		if (ft_tolower(c_s1[i]) != ft_tolower(c_s2[i]))
			return (c_s1[i] - c_s2[i]);
		i++;
	}
	return (c_s1[i] - c_s2[i]);
}
