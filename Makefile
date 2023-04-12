NAME = minishell
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=address -g3
CC = cc 

SRC =	minishell.c \
		minishell_help.c \
		parse/Libft/ft_split.c \
		parse/Libft/ft_strlen.c \
		parse/Libft/ft_substr.c \
		parse/Libft/ft_strjoin.c \
		parse/Libft/ft_calloc.c \
		parse/Libft/ft_strdup.c \
		parse/Libft/ft_lstnew.c \
		parse/Libft/ft_lstadd_front.c \
		parse/Libft/ft_lstadd_back.c parse/Libft/ft_strtrim.c\
		parse/splitpath.c \
		parse/convert_2d_1d.c parse/helpers2.c \
		parse/expander.c parse/expander_help.c parse/expander_help1.c\
		parse/setting_up_input.c \
		parse/split_cmds.c parse/split_cmds_help.c exec/executing.c exec/executing1.c  exec/executing2.c  exec/executing3.c exec/executing4.c exec/executing5.c exec/executing6.c exec/executing7.c exec/executing8.c exec/executing9.c exec/executing10.c exec/executing11.c\
		parse/syntax_errors.c parse/syntax_errors_help.c\
		exec/BUILTIN/unset.c  exec/BUILTIN/unset2.c  exec/BUILTIN/export2.c exec/BUILTIN/export4.c exec/BUILTIN/export3.c exec/BUILTIN/export1.c exec/BUILTIN/cd_utils.c exec/utils2.c exec/utils3.c exec/BUILTIN/echo.c exec/BUILTIN/exit.c exec/printerr.c exec/BUILTIN/pwd.c exec/utils.c  exec/BUILTIN/env.c exec/BUILTIN/cd.c exec/BUILTIN/export.c


OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS) -lreadline  -lreadline -L/Users/sel-biyy/goinfre/homebrew/opt/readline/lib -I/Users/sel-biyy/goinfre/homebrew/opt/readline/include  $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	$(RM) $(OBJS)

fclean :  clean
	$(RM) $(NAME)

re : fclean all