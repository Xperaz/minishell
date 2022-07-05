/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:23:29 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 02:20:24 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_rest(int i)
{
	t_env	*ptr;
	char	*tab1;
	char	*tab2;

	ptr = g_msh.dup_envp;
	while (ptr)
	{
		tab1 = ft_strtrim(ptr->key, "=");
		tab2 = ft_strtrim(g_msh.sort_env[i], "=");
		if (ft_strcmp(tab1, tab2) == 0)
		{
			if (ft_strchr(ptr->key, '='))
				printf("%s\"%s\"\n", ptr->key, ptr->value);
			else
			{
				if (ptr->key)
					printf("%s\n", ptr->key);
			}
		}
		free(tab1);
		free(tab2);
		ptr = ptr->next;
	}
}

/* **************************************************** */
/*                       🅴🅽🆅                          */
/* **************************************************** */

int	tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	sort(void)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (g_msh.sort_env[i] != NULL)
	{
		j = i + 1;
		while (g_msh.sort_env[j] != NULL)
		{
			if (ft_strcmp(g_msh.sort_env[i], g_msh.sort_env[j]) > 0)
			{
				temp = g_msh.sort_env[i];
				g_msh.sort_env[i] = g_msh.sort_env[j];
				g_msh.sort_env[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/* **************************************************** */
/*                       🅴🅽🆅                          */
/* **************************************************** */

void	export_env(void)
{
	int		i;

	i = 0;
	sort();
	while (g_msh.sort_env[i])
	{
		printf("%s", "declare -x ");
		print_rest(i);
		i++;
	}
}

/* **************************************************** */
/*                       🅴🅽🆅                          */
/* **************************************************** */

int	env(int state)
{
	t_env	*ptr;

	ptr = g_msh.dup_envp;
	if (state == ADD_FUTERS)
		export_env();
	else
	{
		if (g_msh.cmd->cmd[1])
			return (quit_minishell(1, "env: No such file or directory"), 1);
		else
		{
			while (ptr != NULL)
			{
				if (strstr(ptr->key, "=") != NULL)
				{
					printf("%s", ptr->key);
					printf("%s\n", ptr->value);
				}
				ptr = ptr->next;
			}
		}
	}
	return (0);
}
