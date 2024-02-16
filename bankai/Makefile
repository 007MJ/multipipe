NAME     = bankai
CC       = gcc
CFLAGS    = -Wall -Werror -Wextra

RM       = rm -fr

SRC      =  main.c \
			lib/free_str.c lib/ft_memmove.c lib/ft_split.c lib/ft_strjoin.c lib/ft_strlen.c lib/ft_strncmp.c lib/ft_memcpy.c lib/new_node.c lib/append.c \
			utils/path.c utils/close_pipes.c utils/run_command.c utils/init_pipes.c utils/execute_commands.c utils/change_pipe.c utils/wait_childs.c utils/array_childs_ids.c\
			parsing/pars.c


INCLUDE_DIR = include 
READLINE_ = readline-8.2

READLINE_DIR = $(INCLUDE_DIR)/readline 

LIBRD = $(READLINE_DIR)/bin/libreadline.a $(READLINE_DIR)/bin/libhistory.a
LIBS = -lreadline -lcurses $(LIBRD)

OBJSFILE = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJSFILE) 
	$(CC) $(CFLAGS) $(OBJSFILE) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean :
	$(RM) $(OBJSFILE)

fclean: clean
	$(RM) $(NAME)

re : fclean all 