/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <aouhadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:47:40 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/03 23:28:18 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_id(int p)
{
	char	*val;

	if (p % 2 == 0)
	{
		if (p == 2)
			val = ft_strdup("10000");
		else
			val = ft_strjoin("10000", val);
	}
	return (val);
}

void	replace_id(char *ptr, t_dinfo *info)
{
	info->val1[info->j] = '\0';
	if (info->j % 2 != 0)
		info->val1[info->j - 1] = 0;
	replace_sub(&ptr, info->val1, info->val);
	free(info->val);
}

int	all_vars(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] != '$')
			return (0);
		i++;
	}
	return (1);
}

void	call_expander(t_dinfo *info, char *com)
{
	while (info->sub[++info->j] == '$')
	{
		info->val = get_id(info->p);
		info->val1[info->j] = info->sub[info->j];
		info->p++;
	}
	if (info->j % 2 == 0 || info->p > 2)
		replace_id(com, info);
}

void	info_init(t_dinfo *info, char *cmd)
{
	info->sub = dollar_substr(cmd);
	info->flag = 1;
	info->j = -1;
	info->p = 1;
	info->val = NULL;
	info->val1 = malloc(sizeof(char) * ft_strlen("10000"));
}
