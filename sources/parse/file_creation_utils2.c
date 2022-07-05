/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_creation_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:07:25 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/04 23:12:40 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_file2(t_command *node)
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
	return (-1);
}

void	open_redirect_out1(char *fl, t_command *node)
{
	int	fd;

	fd = open(fl, O_CREAT, S_IRWXU);
	node->outfile = fd;
}

void	free_2_tab(char *s1, char *s2)
{
	free(s1);
	free(s2);
}
