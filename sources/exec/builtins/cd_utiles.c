/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:25:53 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/04 22:27:48 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	old_pwd(char **key, char **value, char *pwd)
{
	char	*tmp;

	if (ft_strcmp(*key, "OLDPWD") == 0)
	{
		tmp = *key;
		*key = ft_strjoin(*key, "=");
		free(tmp);
	}
	if (pwd)
		*value = ft_strdup(pwd);
}
