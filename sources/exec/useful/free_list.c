/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:57:39 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:33:48 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_cmd(void)
{
	t_command	*tmp;

	while ((g_msh.cmd) != NULL)
	{
		printf("%s\n", g_msh.cmd->cmd[0]);
		printf("%s\n", g_msh.cmd->cmd[1]);
		tmp = g_msh.cmd;
		g_msh.cmd = g_msh.cmd->next;
		free_tab(tmp->cmd);
		free(tmp);
	}
}

void	free_all(void)
{
	t_env	*ptr;
	t_env	*de;

	free_cmd();
	ptr = g_msh.dup_envp;
	if (g_msh.dup_envp == NULL)
		return ;
	while (ptr != NULL)
	{
		de = ptr->next;
		free(ptr->key);
		free(ptr->value);
		free(ptr);
		ptr = de;
	}
	g_msh.dup_envp = NULL;
}

void	free_env(void)
{
	int	i;

	i = 0;
	while (g_msh.my_env[i])
	{
		free(g_msh.my_env[i]);
		free(g_msh.sort_env[i]);
		i++;
	}
	free(g_msh.my_env);
	free(g_msh.sort_env);
}
