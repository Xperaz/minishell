/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utiles3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:18 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:32:41 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_env_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

int	state(char *input)
{
	struct stat	buff;

	if (stat(input, &buff))
		return (0);
	if (!S_ISREG(buff.st_mode) && S_ISDIR(buff.st_mode))
		return (1);
	return (0);
}

void	set_pipes(void)
{
	int	i;

	i = 0;
	if (g_msh.cmd_number > 0)
	{
		g_msh.pipefd = (int *) malloc(sizeof(int) * 2 * (g_msh.cmd_number - 1));
		if (!g_msh.pipefd)
			quit_minishell(errno, "Cannot allocate memory");
	}
	i = 0;
	while (i <= g_msh.cmd_number - 1)
	{
		if (pipe(g_msh.pipefd + 2 * i) < 0)
			quit_minishell(errno, "Broken pipe");
		i++;
	}
}

void	close_pipes(void)
{
	int	i;

	i = 0;
	while (i < 2 * (g_msh.cmd_number - 1))
	{
		close (g_msh.pipefd[i]);
		i++;
	}
}
