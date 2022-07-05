/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:20:05 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/04 23:05:43 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	quit_minishell(int exit_code, char *error_msg)
{
	if (exit_code != 258)
	{
		printf("%s\n", error_msg);
		g_msh.exit_status = exit_code;
	}
	else
		g_msh.exit_status = exit_code;
}
