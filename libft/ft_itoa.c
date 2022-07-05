/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:46:32 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/15 18:15:28 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_w(long int i, int c, char *ptr)
{
	int	rest;

	while (i >= 0)
	{
		rest = i % 10;
		i = i / 10;
		ptr[c] = rest + 48;
		if (i == 0)
			break ;
		c--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	long int	i;
	int			c;
	char		*ptr;

	i = n;
	c = 0;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	if (i <= 0)
		c++;
	ptr = (char *)malloc(c * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[c] = '\0';
	c--;
	if (i < 0)
	{
		ptr[0] = '-';
		i = i * -1;
	}
	return (ft_print_w(i, c, ptr));
}
