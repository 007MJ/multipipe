NAME     = pipes
CC       = gcc
CFLAGS    = -Wall -Werror -Wextra

RM       = rm -fr
SRC      = free_str.c ft_memmove.c ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c main.c path.c ft_memcpy.c
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