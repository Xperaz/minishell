CC = gcc 

FLAGS = -Wall -Wextra -Werror 
#-fsanitize=address -fno-omit-frame-pointer

EXEC_FILES = sources/exec/

PARSE_FILES = sources/parse/

E_SRC  = execute.c useful/quite.c useful/free_list.c useful/exec_utiles.c useful/exec_utiles1.c useful/exec_utiles2.c\
		 useful/exec_utiles3.c useful/her_doc.c\
		 useful/non_execve.c builtins/echo.c builtins/pwd.c builtins/env.c builtins/cd.c builtins/export.c builtins/unset.c builtins/exit.c \
			builtins/cd_utiles.c
	   
	   
P_SRC  =  minishell.c checker.c list_utils.c lis_utils2.c tokenizer.c toknizer_utils.c syntax_validation.c cmd_list_utils.c parser.c parser_utils.c \
	      expander.c expander_utils.c files_creation.c files_creation_utils.c heredoc_utils.c signals.c remove_unused_tab.c\
		  expander_utils2.c file_creation_utils2.c expander_utils3.c\


PARSE = $(addprefix $(PARSE_FILES), $(P_SRC))
EXEC  = $(addprefix $(EXEC_FILES), $(E_SRC))


P_OBJ = $(PARSE:%.c=%.o)
E_OBJ = $(EXEC:%.c=%.o)

NAME = minishell

all  :$(NAME)

$(NAME) : $(P_OBJ) $(E_OBJ)
		@make -C ./libft
		@make bonus -C ./libft
		@$(CC) $(FLAGS) ./libft/libft.a $(P_OBJ) $(E_OBJ) -o $(NAME) -L$(shell brew --prefix readline)/lib -lreadline
		@echo "\n \n$(GREEN)$(TAB)$(TAB)"CREATED" $(RESET)"

%.o : %.c includes/minishell.h  libft/libft.h
	@$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@

clean :
		@rm -rf $(E_OBJ) $(P_OBJ)
		@make fclean -C ./libft

fclean : clean
		@rm -rf $(NAME)

re		: clean all


.PHONY : all clean fclean re 


GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = \033[0;35m
TAB = "\	"