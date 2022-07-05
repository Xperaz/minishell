/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <aouhadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:56:43 by aouhadou          #+#    #+#             */
/*   Updated: 2022/06/30 18:02:50 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token_type	token_found(const char *cmd_line)
{
	if (ft_strncmp(cmd_line, "<<", 2) == 0)
		return (AS_input);
	else if (ft_strncmp(cmd_line, "<>", 2) == 0)
		return (F_OUTPUT);
	else if (ft_strncmp(cmd_line, ">>", 2) == 0)
		return (AS_output);
	else if (ft_strncmp(cmd_line, "<", 1) == 0)
		return (INPUT);
	else if (ft_strncmp(cmd_line, ">", 1) == 0)
		return (OUTPUT);
	else if (ft_strncmp(cmd_line, "|", 1) == 0)
		return (TOKEN_PIPE);
	else
		return (TOKEN_WORD);
}

int	get_word_token_size(char *cmd_line)
{
	size_t	i;
	int		double_quote;
	int		single_quote;

	double_quote = 0;
	single_quote = 0;
	i = 0;
	while (cmd_line[i] && (!ft_strchr(" |<>", cmd_line[i])
			|| double_quote || single_quote))
	{
		if (cmd_line[i] == '\"' && !single_quote)
			double_quote = 1 - double_quote;
		else if (cmd_line[i] == '\'' && !double_quote)
			single_quote = 1 - single_quote;
		i++;
	}
	return (i);
}

void	get_next_token(char *cmd_line, int *size, t_token_type *type)
{
	*size = 0;
	*type = token_found(cmd_line);
	if (*type != TOKEN_WORD)
	{
		*size = 1;
		if (*type == AS_input || *type == AS_output || *type == F_OUTPUT)
			*size = 2;
	}
	else
		*size = get_word_token_size(cmd_line);
}

t_token	*ft_tokens(char *cmd_line)
{
	t_token	*token;
	t_token	tokn;
	int		i;

	token = NULL;
	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == ' ')
			i++;
		else
		{
			get_next_token(cmd_line + i, &tokn.size, &tokn.type);
			add_to_end(&token, new_token(cmd_line + i, tokn.size, tokn.type));
			i += tokn.size;
		}
	}
	return (token);
}
