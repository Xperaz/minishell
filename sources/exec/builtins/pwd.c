/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:16:02 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:30:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	get_from(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
	{
		printf("%s\n", pwd);
		free(pwd);
		return (0);
	}
	return (1);
}

int	pwd(void)
{
	char	*pwd;
	t_env	*ptr;

	ptr = g_msh.dup_envp;
	if (g_msh.cmd->cmd[1])
	{
		if (g_msh.cmd->cmd[1][0] == '-' && g_msh.cmd->cmd[1][1])
			return (quit_minishell(1, "pwd: invalid option"), 1);
	}
	if (!get_from())
		return (0);
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->key, "PWD=") == 0)
		{
			printf("%s\n", ptr->value);
			return (0);
		}
		ptr = ptr->next;
	}
	return (0);
}
