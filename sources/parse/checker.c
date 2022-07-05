/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:55:41 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/04 21:03:33 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_error(void)
{
	printf("%s\n", ERRORS);
	rl_on_new_line();
}

void	ft_check(char *command)
{
	if (command[0] != '\0')
		add_history(command);
}

int	command_checker(char *command)
{
	int	i;
	int	quotes;

	i = -1;
	quotes = 0;
	while (command[++i])
	{
		if (quotes == 0 && command[i] == '"')
			quotes = 2;
		else if (quotes == 2 && command[i] == '"')
			quotes = 0;
		else if (quotes == 0 && command[i] == '\'')
			quotes = 1;
		else if (quotes == 1 && command[i] == '\'')
			quotes = 0;
		else if (quotes == 0 && (command[i] == '\\' || command[i] == ';'))
			return (1);
	}
	if (quotes != 0)
		return (1);
	return (0);
}
