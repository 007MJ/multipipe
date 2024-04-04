NAME     = bankai
CC       = gcc
CFLAGS    = -Wall -Werror -Wextra -g -fsanitize=address

RM       = rm -fr

SRC      =  main.c \
			lib/free_str.c lib/ft_memmove.c lib/ft_split.c lib/ft_strjoin.c lib/ft_strlen.c lib/ft_strncmp.c lib/ft_memcpy.c lib/new_cmd.c lib/append.c lib/ft_calloc.c lib/ft_bzero.c lib/ft_strdup.c\
			pipes/path.c pipes/close_pipes.c pipes/run_command.c pipes/init_pipes.c pipes/execute_commands.c pipes/change_pipe.c pipes/wait_childs.c pipes/array_childs_ids.c\
			parsing/pars.c parsing/check_quote.c parsing/remove_quote.c\
			parsing/expan_pars/type_of_cmd.c parsing/expan_pars/remove_first_quote.c\
			parsing/space/put_back_space.c parsing/space/replace_space.c\
			fusion/setting_run.c


INCLUDE_DIR = include 
READLINE = readline-8.2

READLINE_DIR = include/readline 

LIBRD = include/readline/bin/libreadline.a include/readline/bin/libhistory.a
LIBS = -lreadline -lcurses $(LIBRD)

OBJSFILE = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBRD) $(OBJSFILE) 
	$(CC) $(CFLAGS) $(OBJSFILE) -o $(NAME) $(LIBS)

%.o : %.c
	$(CC) $(CFLAGS) -I include -o $@ -c $^


$(LIBRD):
	curl -O ftp://ftp.cwru.edu/pub/bash/readline-8.2.tar.gz
	tar -zxvf readline-8.2.tar.gz
	@rm -rf readline-8.2.tar.gz
	@cd readline-8.2 && bash configure && make
	@mkdir -p include/readline/bin
	@mv ./readline-8.2/*.h include/readline
	@mv ./readline-8.2/*.a include/readline/bin
	@rm -rf readline-8.2

clean :
	$(RM) $(OBJSFILE)

fclean: clean
	$(RM) $(NAME)

re : fclean all 