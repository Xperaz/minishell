/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utiles1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:04:55 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:30:56 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	first(t_command **ptr)
{
	if (!(*ptr)->cmd[0])
		(*ptr)->cmd_type = -1;
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

t_command	*ft_new(void *content)
{
	t_command	*ptr;

	ptr = (t_command *)malloc (sizeof(t_command));
	if (ptr == NULL)
		quit_minishell(errno, strerror(errno));
	ptr->cmd = ft_sp_split(content, ' ');
	ptr->next = NULL;
	return (ptr);
}
/* **************************************************** */
/*                                                      */
/* **************************************************** */

t_command	*last(t_command *ptr)
{
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	ft_add_back(t_command **lst, t_command *new)
{
	t_command	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = last(*lst);
		last_node->next = new;
	}
}

/* **************************************************** */
/*                                                      */
/* **************************************************** */

void	catagorize(void)
{
	t_command	*ptr;

	ptr = g_msh.cmd;
	first(&ptr);
	while (ptr && ptr->cmd[0])
	{
		if (ft_strcmp(ptr->cmd[0], "exit") == 0)
			ptr->cmd_type = EXIT;
		else if (ft_strcmp(ptr->cmd[0], "cd") == 0)
			ptr->cmd_type = CD;
		else if (ft_strcmp(ptr->cmd[0], "env") == 0)
			ptr->cmd_type = ENV;
		else if (ft_strcmp(ptr->cmd[0], "unset") == 0)
			ptr->cmd_type = UNSET;
		else if (ft_strcmp(ptr->cmd[0], "export") == 0)
			ptr->cmd_type = EXPORT;
		else if (ft_strcmp(ptr->cmd[0], "echo") == 0)
			ptr->cmd_type = ECHO;
		else if (ft_strcmp(ptr->cmd[0], "pwd") == 0)
			ptr->cmd_type = PWD;
		else
			ptr->cmd_type = EXECVE;
		g_msh.cmd_number++;
		ptr = ptr->next;
	}
}
