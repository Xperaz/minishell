/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:08:19 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/05 02:31:47 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

typedef struct expander_utils2
{
	char	*array;
	int		j;
	char	*tab;
}	t_expand;

void	ex_free(t_dinfo info)
{
	if (info.flag == 3)
	{
		free(info.sub);
		free_tab(info.ptr);
	}
	else
		free(info.sub);
}

int	check_dollar(t_command	*list)
{
	t_command	*tmp;
	int			i;

	tmp = list;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			if (is_dollar(tmp->cmd[i]) != -1)
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*get_env1(char *env)
{	
	t_env	*ptr;
	char	*tab;

	ptr = g_msh.dup_envp;
	while (ptr)
	{
		tab = ft_strndup(ptr->key, ft_strlen(ptr->key) - 1);
		if (!ft_strcmp1(env, tab))
		{
			free(tab);
			return (ft_strdup(ptr->value));
		}
		free(tab);
		ptr = ptr->next;
	}
	return (NULL);
}

void	fill_tab(char **ptr, char **dest)
{
	t_expand	inf;

	inf.j = -1;
	while (ptr[++inf.j])
	{
		inf.array = ft_strdup(ptr[inf.j]);
		ft_memmove(inf.array + 1, inf.array, ft_strlen(inf.array) + 1);
		inf.array[0] = '$';
		inf.tab = get_env1(ptr[inf.j]);
		if (!inf.tab)
			replace_sub(dest, inf.array, "");
		free_2_tab(inf.tab, inf.array);
	}
	inf.j = -1;
	while (ptr[++inf.j])
	{
		inf.array = ft_strdup(ptr[inf.j]);
		ft_memmove(inf.array + 1, inf.array, ft_strlen(inf.array) + 1);
		inf.array[0] = '$';
		inf.tab = get_env1(ptr[inf.j]);
		if (inf.tab)
			replace_sub(dest, inf.array, inf.tab);
		free_2_tab(inf.tab, inf.array);
	}
}

void	ft_break(int *flag, char *sub)
{
	*flag = 0;
	free(sub);
}
