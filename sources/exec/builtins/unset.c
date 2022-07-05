/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:14:52 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 03:24:34 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

typedef struct s_var
{
	t_env	*ptr_del;
	t_env	*ptr;
	char	*str;
	int		flag;
}	t_var;

int	first_variable(char *to_remove)
{
	t_env	*ptr_del;
	t_env	**ptr;
	char	*str;

	ptr = &g_msh.dup_envp;
	str = ft_strtrim((*ptr)->key, "=");
	if (!ft_strcmp(str, to_remove))
	{
		ptr_del = *ptr;
		(*ptr) = (*ptr)->next;
		if (ptr_del->value)
			free(ptr_del->value);
		free(ptr_del->key);
		free(ptr_del);
		free(str);
		return (0);
	}
	g_msh.dup_envp = *ptr;
	free(str);
	return (1);
}

void	unset_loop(char *to_remove, t_var *info)
{
	info->flag = 0;
	info->ptr = g_msh.dup_envp;
	while (info->ptr != NULL)
	{
		if (info->ptr->next)
		{
			info->str = ft_strtrim(info->ptr->next->key, "=");
			if (!ft_strcmp(info->str, to_remove))
			{
				info->flag = 1;
				info->ptr_del = info->ptr->next;
				if (info->ptr->next->next != NULL)
					info->ptr->next = info->ptr->next->next;
				else
					info->ptr->next = NULL;
				if (info->ptr_del->value)
					free(info->ptr_del->value);
				free_2_tab(info->str, info->ptr_del->key);
			}
			if (info->flag == 0)
				free(info->str);
		}
		info->ptr = info->ptr->next;
	}
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

int	remove_variable(char *to_remove)
{
	t_var	info;

	info.ptr = g_msh.dup_envp;
	if (info.ptr == NULL)
		return (0);
	if (first_variable(to_remove) == 0)
		return (0);
	unset_loop(to_remove, &info);
	info.ptr = g_msh.dup_envp;
	return (0);
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	unset(void)
{
	int	i;
	int	j;

	i = 1;
	while (g_msh.cmd->cmd[i] != NULL)
	{
		j = 0;
		while (g_msh.cmd->cmd[i][j])
		{
			if (!ft_isalpha(g_msh.cmd->cmd[i][0]) || \
			(!ft_isalnum(g_msh.cmd->cmd[i][j]) && g_msh.cmd->cmd[i][j] != '_'))
			{
				quit_minishell(1, "unset: not a valid identifier");
				break ;
			}
			j++;
		}
		remove_variable(g_msh.cmd->cmd[i]);
		i++;
	}
}
