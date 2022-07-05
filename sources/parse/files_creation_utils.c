/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_creation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <aouhadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:56:06 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/03 21:39:28 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free(char *s1, char *s2)
{
	ft_bzero(s1, ft_strlen(s1));
	ft_bzero(s2, ft_strlen(s2));
}

int	open_redirect_input(char *file, t_command *node)
{
	int	fd;
	int	flag;

	flag = 1;
	if ((access(file, F_OK)) == 0)
	{
		fd = open(file, O_WRONLY, S_IRWXU);
		node->infile = fd;
	}
	else
		flag = 0;
	return (flag);
}

void	open_app_redirect_out(char *file, t_command *node)
{
	int	fd;

	if ((access(file, F_OK)) == 0)
	{
		fd = open(file, O_APPEND | O_WRONLY, S_IWUSR);
		node->outfile = fd;
	}
	else
	{
		fd = open(file, O_CREAT, S_IWUSR);
		node->outfile = fd;
	}
}

void	open_redirect_out(char *fl, t_command *node)
{
	int	fd;

	fd = open(fl, O_TRUNC | O_RDWR | O_CREAT, 0666);
	node->outfile = fd;
}

void	ft_out_file(t_command *node, int *i)
{
	if (!ft_strcmp1(node->cmd[*i], ">"))
	{
		open_redirect_out(node->cmd[*i + 1], node);
		ft_free(node->cmd[*i + 1], node->cmd[*i]);
	}
	else if (!ft_strcmp1(node->cmd[*i], "<>"))
	{
		open_redirect_out1(node->cmd[*i + 1], node);
		ft_free(node->cmd[*i + 1], node->cmd[*i]);
	}
	else if (!ft_strcmp1(node->cmd[*i], ">>"))
	{
		open_app_redirect_out(node->cmd[*i + 1], node);
		ft_free(node->cmd[*i + 1], node->cmd[*i]);
	}
}
