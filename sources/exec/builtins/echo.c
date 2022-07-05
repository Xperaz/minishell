/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:06:06 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 02:30:50 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	status(void)
{
	if (g_msh.cmd->cmd[1] && ft_strcmp(g_msh.cmd->cmd[1], "$?") == 0)
	{
		if (g_msh.syntax_err == 1)
		{
			printf("%d\n", 258);
			g_msh.syntax_err = 0;
		}
		else
			printf("%d\n", g_msh.exit_status);
		return (0);
	}
	return (1);
}

/* **************************************************** */
/*                   🅲🅷🅴🅲🅺_🅵🅻🅰🅶                   */
/* **************************************************** */

int	check_flag(char *flag)
{
	int	i;

	i = 1;
	if (flag[0] == '-' && flag[i] == 'n')
	{
		while (flag[i])
		{
			if (flag[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

/* **************************************************** */
/*                       🅴🅲🅷🅾                         */
/* **************************************************** */

int	echo(void)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!status())
		return (0);
	while (g_msh.cmd->cmd[i])
	{
		if (!check_flag(g_msh.cmd->cmd[i]))
			break ;
		i++;
		flag++;
	}
	while (g_msh.cmd->cmd[i])
	{
		printf("%s", g_msh.cmd->cmd[i]);
		if (g_msh.cmd->cmd[i + 1] != NULL)
			printf("%s", " ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
