/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:45:18 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:11:08 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	get_path(void)
{
	int		i;
	char	*path;
	t_env	*ptr;

	i = 0;
	g_msh.separ_path = NULL;
	ptr = g_msh.dup_envp;
	while (ptr)
	{
		if (ft_strncmp(ptr->key, "PATH=", 5) == 0)
		{
			g_msh.separ_path = ft_split(ptr->value, ':');
			break ;
		}
		ptr = ptr->next;
	}
	if (g_msh.separ_path == NULL)
		g_msh.separ_path = ft_split(_PATH_STDPATH, ':');
	while (g_msh.separ_path[i])
	{
		path = g_msh.separ_path[i];
		g_msh.separ_path[i] = ft_strjoin(path, "/");
		free(path);
		i++;
	}
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	data_management(t_command *cmds, int decission, char **env)
{
	if (decission == ENV)
	{
		get_env(env);
		get_path();
	}
	else
	{
		g_msh.cmd = cmds;
		env_list_to_array();
		catagorize();
	}
}
