/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:07:29 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 01:57:49 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<errno.h>
# include	<unistd.h>
# include	<stdint.h>
# include   <sys/wait.h>
# include   <sys/ioctl.h>
# include	<sys/stat.h>
# include   <paths.h>
# include	"../libft/libft.h"
# include	"structs.h"
# include	"parse.h"
# include   <fcntl.h>
# include   <signal.h>
# include	<readline/history.h>
# include	<readline/readline.h>

# define NODE_ERR   "Error allocating nodes"
# define INVALID	": not a valid identifier"
# define ADD_FUTERS		1
# define SIMPLE		    0
# define IS_ENV         1
# define NO_ENV         0

t_list		*get_list(char **env, t_list *head);
t_list		*create_node(char **command_list);
int			ft_error(char *str, char *err_type, char *command);
int			echo(void);
void		error(char *str);
int			pwd(void);
int			env(int state);
void		cd(void);
void		export(void);
void		unset(void);
void		exec(char *command_list, t_list *env_list);
void		add_back(t_list **head, t_list *new_node);
void		exiting(void);
void		prompt_init(void);
void		quit_minishell(int exit_code, char *error_msg);
void		init(t_list **env_list, char **env);
void		execute(t_command *cmd);
void		ft_add_back(t_command **lst, t_command *new);
void		data_management(t_command *cmds, int decission, char **env);
void		catagorize(void);
int			list_to_array(void);
void		env_list_to_array(void);
void		run_builtins(void);
void		get_env(char **env);
int			ft_env_size(t_env *env);
void		add_env_back(t_env **head, t_env *new_node);
t_env		*create_env_node(char **env, char *str);
void		run_her_doc(char **tab, int fd);
char		*get_env1(char *env);
void		free_all(void);
void		free_env(void);
void		old_pwd(char **key, char **value, char *pwd);
int			state(char *input);
void		set_pipes(void);
void		close_pipes(void);
t_command	*ft_new(void *content);
t_command	*last(t_command *ptr);
void		hide_ctl(void);
void		show_ctl(void);

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define RESET "\033[0m"

#endif