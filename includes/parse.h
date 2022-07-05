/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:46:02 by aouhadou          #+#    #+#             */
/*   Updated: 2022/07/05 01:57:32 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define ERRORS	"shell$> : syntax error unexpected token"

//checker functions
void			ft_check(char *command);
int				command_checker(char *command);
void			print_error(void);
int				ft_strcmp1(char *s1, char *s2);

//lists_utils_functions
void			add_front(t_token **head, char *data);
void			add_to_end(t_token **head, t_token *data);
void			list_clear(t_token **ptr);
void			delete_node(t_token **head, t_token *del_node);
int				lstsize(t_token *lst);
//cmds list_utls
void			add_cmd_to_end(t_command **command, char **new_data);
t_command		*new_cmd_token(char **data);
void			clear_cmds(t_command **head_ref);
void			delete_cmd(t_command **head, t_command *del_node);
int				lstsize2(t_command *lst);
t_token			*new_token(char *data, int size, t_token_type type);
t_token_type	token_found(const char *cmd_line);
int				get_word_token_size(char *cmd_line);
void			get_next_token(char *cmd_line, int *size, t_token_type *type);

//tokenizer_utils
t_token			*ft_tokens(char *line);
char			*ft_strncpy(char *dst, const char *src, int len);
char			*ft_sub_str(const char *src, int len);
void			remove_all_chars(char *str, char c);
int				is_quotes(char *tok);

//Flaging Functions 
void			flag_list(t_token *list);
void			add_flag(t_token *tmp);
int				check_cmd(char *tok);
int				wich_redirection(char *red);

//Syntax analyser
int				invalid_token(char *node);
int				is_operator(char *tok);
int				syntax_validation(t_token *list);

//parser
t_command		*creat_cmds(t_token *node);
char			**remplir_tab(t_token *node, int start);
int				count_size(t_token	*node, int start);
int				remove_quotes(t_command *node);

//expand VARS
void			expand_dollar(t_command *node);
int				check_dollar(t_command	*list);
char			*dollar_substr1(char *str);
char			*dollar_substr(char *str);
int				is_dollar(char *str);
int				get_env_end(char *str);
const char		*ft_strstr(const char *str, const char *to_find);
void			ft_expand(char **dest, char *sub, char *env);
void			ex_free(t_dinfo info);
void			replace_sub(char **str, const char *old, const char *new_);
char			*get_env1(char *env);
void			fill_tab(char **ptr, char **dest);
void			ft_break(int *flag, char *sub);
void			info_init(t_dinfo *info, char *cmd);
void			call_expander(t_dinfo *info, char *com);
int				all_vars(char *ptr);
void			replace_id(char *ptr, t_dinfo *info);
char			*get_id(int p);
void			free_2_tab(char *s1, char *s2);

//files creation
void			ft_free(char *s1, char *s2);
void			*free_node(void *ptr);
void			*free_tab(char **array);
int				is_redirection(char *tok);
int				is_file(t_command *node);
int				open_redirect_input(char *file, t_command *node);
void			open_app_redirect_out(char *file, t_command *node);
void			open_redirect_out(char *fl, t_command *node);
void			ft_out_file(t_command *node, int *i);
void			ft_open(t_command *node);
void			open_files(t_command *node);
int				is_file2(t_command *node);
void			open_redirect_out1(char *fl, t_command *node);

// herduq
char			*ft_strjoin_1(char *s1, char *s2);
void			create_delimters(t_command *node, int *i);

//Remove unused arrays
void			ft_remove_unsed(t_command *node);

//signals
void			handle_sig(int sig);
void			ctrl_d(char *str);

#endif
