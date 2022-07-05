/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:21:49 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 02:31:00 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exiting(void)
{
	printf("exit\n");
	if (g_msh.cmd->cmd[1])
	{
		g_msh.exit_status = ft_atoi(g_msh.cmd->cmd[1]);
		exit(g_msh.exit_status);
	}
	exit (0);
}
