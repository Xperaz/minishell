/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <aouhadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:55:56 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/03 19:46:29 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

const char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	len;

	len = ft_strlen(to_find);
	i = 0;
	if (to_find[i++] == '\0')
		return (str);
	while (*str != '\0')
	{
		if (ft_strncmp(str, to_find, len) == 0)
			return (str);
		str++;
	}
	return (0);
}

int	is_dollar(char *str)
{
	int	i;

	if (ft_strcmp(str, "$?") == 0)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}

int	get_env_end(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '$')
			return (i);
		i++;
	}
	return (i);
}

char	*dollar_substr1(char *str)
{
	char	*sub;
	char	*res;
	int		end;

	sub = ft_strchr(str, '$');
	end = get_env_end(sub);
	res = ft_substr(sub, 1, end - 1);
	return (res);
}

char	*dollar_substr(char *str)
{
	char	*sub;
	char	*res;
	int		end;

	sub = ft_strchr(str, '$');
	end = get_env_end(sub);
	res = ft_substr(sub, 0, end);
	return (res);
}
