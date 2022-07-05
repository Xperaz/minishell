/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:56:40 by aouhadou          #+#    #+#             */
/*   Updated: 2022/06/28 10:51:29 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_is_var(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '"')
			return (34);
		if (var[i] == '\'')
			return (39);
		i++;
	}
	return (0);
}

int	invalid_token(char *node)
{
	int	i;

	i = 0;
	if ((node[0] != '"' && node[0] != '\''))
	{
		while (node[i])
		{
			if ((node[i] == '(' || node[i] == ')'))
				return (0);
			i++;
		}
	}
	else if (!ft_strncmp(node, "()", 2) || !ft_strncmp(node, "||", 2)
		|| !ft_strncmp(node, "&&", 2))
		return (0);
	return (1);
}

int	is_operator(char *tok)
{
	if (!ft_strcmp1(tok, ">") || !ft_strcmp1(tok, "<")
		|| !ft_strcmp1(tok, ">>") || !ft_strcmp1(tok, "|")
		|| !ft_strcmp1(tok, "<>"))
		return (1);
	return (0);
}

int	is_heredoc(char *tok)
{
	if (!ft_strcmp1(tok, "<<"))
		return (1);
	return (0);
}

int	syntax_validation(t_token *list)
{
	t_token	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (!invalid_token(tmp->data))
			return (0);
		else if (is_operator(tmp->data)
			&& (tmp->next == NULL
				|| !ft_strcmp1(tmp->next->data, "|")))
			return (0);
		else if (is_heredoc(tmp->data)
			&& (tmp->next == NULL
				|| is_operator(tmp->next->data) || is_heredoc(tmp->next->data)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
