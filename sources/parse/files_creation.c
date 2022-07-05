/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <aouhadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:56:13 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/03 21:26:01 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_outfile(char *file)
{
	if ((!ft_strcmp1(file, ">")) || (!ft_strcmp1(file, ">>"))
		|| (!ft_strcmp1(file, "<>")))
		return (1);
	return (0);
}

void	ft_open(t_command *node)
{
	int	i;

	i = -1;
	node->del = NULL;
	while (node->cmd[++i])
	{
		if (is_outfile(node->cmd[i]))
			ft_out_file(node, &i);
		else if (!ft_strcmp1(node->cmd[i], "<<"))
			create_delimters(node, &i);
		else if (!ft_strcmp1(node->cmd[i], "<"))
		{
			if (open_redirect_input(node->cmd[i + 1], node))
				ft_free(node->cmd[i + 1], node->cmd[i]);
		}
	}
}

void	open_files(t_command *node)
{
	int			flag;
	t_command	*tmp;

	node->herdoc = 0;
	tmp = node;
	while (tmp)
	{
		tmp->infile = 0;
		tmp->outfile = 1;
		ft_open(tmp);
		if (tmp->herdoc == 1)
		{
			tmp->delims = ft_split(tmp->del, ' ');
			tmp->infile = open(".temp", O_CREAT | O_RDWR | O_TRUNC, 0666);
			run_her_doc(tmp->delims, tmp->infile);
			tmp->infile = open(".temp", O_RDWR);
			free_tab(tmp->delims);
			free(tmp->del);
		}
		tmp = tmp->next;
	}
}

int	is_redirection(char *tok)
{
	if (!ft_strcmp1(tok, ">") || !ft_strcmp1(tok, "<")
		|| !ft_strcmp1(tok, ">>") || !ft_strcmp1(tok, "<<")
		|| !ft_strcmp1(tok, "<>"))
		return (1);
	return (0);
}

int	is_file(t_command *node)
{
	int	i;

	while (node)
	{
		i = 0;
		while (node->cmd[i])
		{
			if (is_redirection(node->cmd[i]))
				return (i);
			i++;
		}
		node = node->next;
	}
	return (0);
}
