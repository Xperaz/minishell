/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:43:07 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:30:51 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	loop_over_env(int add_to, char **table, char *str)
{
	t_env	*ptr;
	char	*ptr1;
	int		i;
	int		j;

	ptr = g_msh.dup_envp;
	while (ptr != NULL)
	{
		ptr1 = ft_strtrim(ptr->key, "=");
		if (ft_strcmp(table[0], ptr1) == 0)
		{
			if (strstr(str, "=") == NULL)
				return (1);
			else if (add_to == 1 && table[1])
				ptr->value = ft_strjoin(ptr->value, table[1]);
			else if (table[1])
				ptr->value = ft_strdup(table[1]);
			else
				ptr->value = "\0";
			return (1);
		}
		free(ptr1);
		ptr = ptr->next;
	}
	return (0);
}

int	already_exist(char **table, char *str)
{
	int	add_to;

	add_to = 0;
	if (ft_strchr(table[0], '+'))
	{
		table[0] = ft_strtrim(table[0], "+");
		add_to = 1;
	}
	if (loop_over_env(add_to, table, str) == 1)
		return (1);
	return (0);
}

/* **************************************************** */
/*                  🅸🅽🆅🅰🅻🅸🅳_🆅🅽                    */
/* **************************************************** */

int	invalid_vn(char	*table)
{
	int	i;

	i = 1;
	if (ft_strlen(ft_strchr(table, '+')) > 1 || \
		(!ft_isalpha(table[0]) && table[0] != '_'))
		return (quit_minishell(1, ft_strjoin(ft_strjoin \
		("export ", table), " : not a valid identifier")), 1);
	while (table[i])
	{
		if (!ft_isdigit(table[i]) && !ft_isalpha(table[i]) && \
			table[i] != '_' && table[i] != '+')
			return (quit_minishell(1, ft_strjoin(ft_strjoin \
			("export ", table), ": not a valid identifier")), 1);
		i++;
	}
	return (0);
}

/* **************************************************** */
/*                 🅴🆇🅿🅾🆁🆃_🆅🅽🅰🅼🅴                  */
/* **************************************************** */

int	export_vname(void)
{
	char	**table;
	t_env	*node;
	int		i;

	i = 1;
	while (g_msh.cmd->cmd[i] != NULL)
	{
		table = ft_sp_split(g_msh.cmd->cmd[i], '=');
		if (!invalid_vn(table[0]))
		{
			if (already_exist(table, g_msh.cmd->cmd[i]) != 1)
			{
				node = create_env_node(table, g_msh.cmd->cmd[i]);
				add_env_back(&g_msh.dup_envp, node);
			}
		}
		i++;
	}
	return (0);
}

/* **************************************************** */
/*                    🅴🆇🅿🅾🆁🆃                        */
/* **************************************************** */

void	export(void)
{
	if (g_msh.cmd->cmd[1] == NULL)
		env(ADD_FUTERS);
	else
		if (export_vname())
			quit_minishell(1, "variable name undefined");
}
