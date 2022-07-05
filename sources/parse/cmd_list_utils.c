/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:55:51 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/03 13:58:30 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*last_cmd(t_command *token)
{
	t_command	*last;

	last = NULL;
	if (token)
	{
		last = token;
		while (last && last->next)
			last = last->next;
	}
	return (last);
}

t_command	*new_cmd_token(char **data)
{
	t_command	*new;

	new = (t_command *)malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->cmd = data;
	new->next = NULL;
	return (new);
}

void	add_cmd_to_end(t_command **command, char **new_data)
{
	t_command	*new_node;
	t_command	*last;

	new_node = (t_command *) malloc(sizeof(t_command));
	new_node->cmd = new_data;
	new_node->next = NULL;
	if (*command == NULL)
	{
		*command = new_node;
		return ;
	}
	last = *command;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void	*free_tab(char **array)
{
	int	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	array = 0;
	return (NULL);
}

void	clear_cmds(t_command **head)
{
	t_command	*tmp;

	while ((*head) != NULL)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free_tab(tmp->cmd);
		free(tmp);
	}
}
