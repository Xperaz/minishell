/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <aouhadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:56:18 by aouhadou          #+#    #+#             */
/*   Updated: 2022/06/30 21:54:39 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin_1(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s2 == NULL)
		s2 = ft_strdup("");
	i = 0;
	j = 0;
	ptr = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof (char));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		ptr[i] = s1[i];
	ptr[i] = ' ';
	i = i + 1;
	j = -1;
	while (++j < ft_strlen(s2))
		ptr[i++] = s2[j];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

void	create_delimters(t_command *node, int *i)
{
	node->herdoc = 1;
	node->infile = 0;
	node->del = ft_strjoin_1(node->del, node->cmd[*i + 1]);
	ft_free(node->cmd[*i + 1], node->cmd[*i]);
}
