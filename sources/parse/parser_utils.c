/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <aouhadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:56:30 by aouhadou          #+#    #+#             */
/*   Updated: 2022/06/30 18:10:09 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_size(t_token	*node, int start)
{
	t_token	*tmp;
	int		i;
	int		compt;

	i = 0;
	tmp = node;
	while (i < start)
	{
		tmp = tmp->next;
		i++;
	}
	compt = 0;
	while (tmp)
	{
		if (!ft_strcmp1(tmp->data, "|"))
			break ;
		compt++;
		tmp = tmp->next;
	}
	return (compt);
}

char	**remplir_tab(t_token *node, int start)
{
	char	**tab;
	int		size;
	t_token	*tmp;	
	int		i;

	size = count_size(node, start);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	tmp = node;
	while (i < start)
	{
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i++] = ft_strdup(tmp->data);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}

int	have_option(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '-' && cmd[i - 1] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	invalid_cmd(char *cmd)
{
	if (have_option(cmd))
	{
		if ((!access(cmd, F_OK)) == 0)
			return (0);
	}
	return (1);
}

int	remove_quotes(t_command *node)
{
	int	i;

	while (node)
	{
		i = 0;
		while (node->cmd[i])
		{
			if (is_quotes(node->cmd[i]))
			{
				if (!invalid_cmd(node->cmd[i]) && node->cmd[i - 1] == 0)
					return (0);
				remove_all_chars(node->cmd[i], is_quotes(node->cmd[i]));
			}
			i++;
		}
		node = node->next;
	}
	return (1);
}
