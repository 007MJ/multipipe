NAME   = pipes
CC     = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
# -fsanitize=address

RM     = rm -fr


SRCS    = main.c ../array_childs_ids.c ../change_pipe.c ../close_pipes.c ../execute_command.c ../init_pipes.c ../path.c ../run_commands.c ../wait_childs.c ../single_command.c ../commands.c\
		../lib/free_str.c ../lib/ft_memmove.c ../lib/ft_split.c ../lib/ft_strjoin.c ../lib/ft_strlen.c ../lib/ft_strncmp.c ../lib/ft_memcpy.c ../lib/new_cmd.c ../lib/append.c ../lib/ft_calloc.c ../lib/ft_bzero.c ../lib/ft_strdup.c\

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all