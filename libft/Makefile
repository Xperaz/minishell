CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC	= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_split.c \
		ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c  ft_striteri.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  ft_putnbr_fd.c \
		ft_strcmp.c ft_lstrcmp.c ft_strcsnp.c ft_strndup.c \
		ft_putstr.c ft_special_split.c \

	
		

SRC_B = ft_lstnew.c	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c \



AR  	= ar rcs

OBJ 	=	$(SRC:%.c=%.o)

OBJ_B	=	$(SRC_B:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $@ $^

%.o : %.c libft.h
	@${CC} ${CFLAGS} -c $<

bonus: ${NAME} $(OBJ_B)
	@$(AR) $^

clean : 
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re

GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = \033[0;35m
TAB = "\	"