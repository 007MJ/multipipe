NAME   = unit
CC     = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
# -fsanitize=address

RM     = rm -fr


SRCS    = main.c ../pipes/array_childs_ids.c ../pipes/change_pipe.c ../pipes/commands.c ../pipes/execute_command.c ../pipes/init_pipes.c ../pipes/path.c ../pipes/run_commands.c ../pipes/single_command.c ../pipes/wait_childs.c \
		../files/manage_files/change_stdint.c ../files/manage_files/change_stdout.c ../files/manage_files/ft_append.c \
		../builtins/function/ft_echo.c ../builtins/function/ft_export.c ../builtins/function/ft_unset.c \
		../builtins/function/utils/addEnvp.c ../builtins/function/utils/ft_strlen_utils.c ../builtins/function/utils/printEnvp.c \
		../pipes/lib/append.c  ../pipes/lib/free_str.c ../pipes/lib/ft_bzero.c ../pipes/lib/ft_calloc.c ../pipes/lib/ft_memcpy.c ../pipes/lib/ft_memmove.c ../pipes/lib/ft_split.c ../pipes/lib/ft_strdup.c ../pipes/lib/ft_strjoin.c ../pipes/lib/ft_strlen.c ../pipes/lib/ft_strncmp.c ../pipes/lib/new_cmd.c 

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