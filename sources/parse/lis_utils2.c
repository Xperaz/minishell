/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:34:59 by aouhadou          #+#    #+#             */
/*   Updated: 2022/06/28 10:51:09 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lstsize2(t_command *lst)
{
	int			i;
	t_command	*new;

	new = lst;
	i = 0;
	while (new != NULL)
	{
		i++;
		new = new->next;
	}
	return (i);
}

int	lstsize(t_token *lst)
{
	int		i;
	t_token	*new;

	new = lst;
	i = 0;
	while (new != NULL)
	{
		i++;
		new = new->next;
	}
	return (i);
}
