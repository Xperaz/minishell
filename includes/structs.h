/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:19:48 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:58:21 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "minishell.h"

typedef enum e_token_type		t_token_type;

enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	INPUT,
	AS_input,
	OUTPUT,
	AS_output,
	TOKEN_START,
	TOKEN_LINE,
	F_OUTPUT,
	D_QUOTES = 10,
};

// ~ ******************** ENUM ************************* ~ \\

typedef enum e_builtin {
	ECHO,
	CD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	PWD,
	EXECVE
}	t_builtins;

// ~ ********************* 🆃🅾🅺🅴🅽🆂 *********************** ~ \\

typedef struct tokens {
	int				size;
	t_token_type	type;
	char			*data;
	int				key;
	int				taille;
	struct tokens	*next;
	struct tokens	*prev;
}	t_token;

// ~ ********************* 🅲🅾🅼🅼🅰🅽🅳 🆂🆃🆁🆄🅲🆃 *********************** ~ \\

typedef struct command {
	char			**cmd;
	int				infile;
	int				outfile;
	int				herdoc;
	char			**delims;
	char			*del;
	int				flag;
	struct command	*next;
	t_builtins		cmd_type;
}	t_command;

// ~ ********************* 🅴🅽🆅🅸🆁🅴🅼🅴🅽🆃 🆂🆃🆁🆄🅲🆃 *********************** ~ \\

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// ~ ******************** DOLAR ************************* ~ \\

typedef struct dollar
{
	size_t		i;
	size_t		c_d;
	size_t		x;
	size_t		t;
	const char	*temp;
	char		*buff;
}	t_info;

typedef struct dollar_info
{
	int		i;
	char	*sub;
	int		flag;
	char	**ptr;
	int		j;
	int		p;
	char	*val;
	char	*val1;
}	t_dinfo;

// ~ ******************** REMOVE UNUSED ARRAYS ************************* ~ \\

typedef struct unsed
{
	int		count;
	int		total;
	char	**tab;
	int		i;
	int		j;	
}	t_remove;

// ~ ********************* 🅶🅻🅾🅱🅰🅻 🆂🆃🆁🆄🅲🆃 *********************** ~ \\

typedef struct s_msh
{
	t_env		*dup_envp;
	t_command	*cmd;
	t_token		*token;
	char		**separ_path;
	char		**my_env;
	char		**sort_env;
	int			pid;
	int			cmd_number;
	int			pipe_id;
	int			*pipefd;
	int			syntax_err;
	int			h_fd[2];
	int			signal;
	uint8_t		exit_status;
}				t_msh;
t_msh							g_msh;

#endif