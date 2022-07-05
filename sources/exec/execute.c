/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:08:16 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:33:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	special_futers_for_cmd(void)
{
	t_env	*ptr;

	ptr = g_msh.dup_envp;
	if (ft_strcmp(g_msh.cmd->cmd[0], "./minishell") == 0)
	{
		while (ptr)
		{
			if (ft_strcmp(ptr->key, "SHLVL=") == 0)
			{
				ptr->value = ft_itoa(ft_atoi(ptr->value) + 1);
			}
			if (ft_strcmp(ptr->key, "OLDPWD=") == 0)
			{
				ft_strtrim(ptr->key, "=");
				ptr->value = NULL;
			}
			ptr = ptr->next;
		}
	}
	env_list_to_array();
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	command_runing(void)
{
	char	*command;
	int		i;

	i = 0;
	while (g_msh.separ_path[i] && g_msh.cmd->cmd[0])
	{
		if (access(g_msh.cmd->cmd[0], F_OK) == 0)
			command = g_msh.cmd->cmd[0];
		else
			command = ft_strjoin(g_msh.separ_path[i], g_msh.cmd->cmd[0]);
		if (access(command, F_OK) == 0)
			break ;
		i++;
	}
	if (access(command, F_OK) == 0)
		execve(command, g_msh.cmd->cmd, g_msh.my_env);
	if (state(command))
		quit_minishell(126, ft_strjoin(ft_strjoin("bash: ", command) \
		, " is a directory"));
	else
		quit_minishell(127, ft_strjoin(ft_strjoin("bash: ", command), \
		" commaned not found"));
	exit(1);
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	dup_the_data(int command, t_command **cmd)
{
	if (g_msh.cmd_number == 1 && (*cmd)->cmd_type != EXECVE)
		run_builtins();
	else
	{
		g_msh.pid = fork();
		if (g_msh.pid == 0)
		{
			g_msh.signal = 2;
			special_futers_for_cmd();
			if (command != 0)
				dup2(g_msh.pipefd[(command - 1) * 2], STDIN_FILENO);
			if (command != g_msh.cmd_number - 1)
				dup2(g_msh.pipefd[command * 2 + 1], STDOUT_FILENO);
			if ((*cmd)->outfile != 1)
				dup2((*cmd)->outfile, STDOUT_FILENO);
			if ((*cmd)->infile != 0)
				dup2((*cmd)->infile, STDIN_FILENO);
			close_pipes();
			command_runing();
		}
	}	
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	execute_cmd(void)
{
	int		command;
	char	*str;
	int		status;
	int		pid;

	command = 0;
	status = 0;
	if (g_msh.cmd_number > 1 && g_msh.cmd->cmd_type == EXECVE)
		set_pipes();
	g_msh.signal = 5;
	while (g_msh.cmd)
	{
		dup_the_data(command, &g_msh.cmd);
		command++;
		g_msh.cmd = g_msh.cmd->next;
	}
	close_pipes();
	waitpid(g_msh.pid, (int *)&g_msh.exit_status, 0);
	waitpid(-1, NULL, 0);
	g_msh.signal = 0;
	if (WIFEXITED(g_msh.exit_status))
		g_msh.exit_status = WEXITSTATUS(g_msh.exit_status);
	else if (WIFSIGNALED(g_msh.exit_status))
		g_msh.exit_status = WTERMSIG(g_msh.exit_status) + 128;
}

/* **************************************************** */
/*                        🅼🅰🅸🅽                       */
/* **************************************************** */

void	execute(t_command *cmds)
{
	g_msh.pipe_id = 0;
	data_management(cmds, NO_ENV, NULL);
	execute_cmd();
	free_env();
	data_management(cmds, NO_ENV, NULL);
	g_msh.cmd_number = 0;
}
