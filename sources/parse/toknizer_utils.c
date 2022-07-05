/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toknizer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:56:47 by aouhadou          #+#    #+#             */
/*   Updated: 2022/06/28 10:51:35 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_all_chars(char *str, char c)
{
	char	*pr;
	char	*pw;

	pr = str;
	pw = str;
	while (*pr)
	{
		*pw = *pr++;
		pw += (*pw != c);
	}
	*pw = '\0';
}

char	*ft_strncpy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_sub_str(const char *src, int len)
{
	char	*substr;

	if (!src)
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	return (ft_strncpy(substr, src, len));
}

int	is_two(char *tok, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tok[i])
	{
		if (tok[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	is_quotes(char *tok)
{
	if (tok[0] == 39)
		return (39);
	else if (tok[0] == 34)
		return (34);
	else if (is_two(tok, 39) == 2)
		return (39);
	else if (is_two(tok, 34) == 2)
		return (34);
	else
		return (0);
}
