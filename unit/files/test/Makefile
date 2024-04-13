# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 18:06:53 by mnshimiy          #+#    #+#              #
#    Updated: 2024/04/09 22:28:09 by mnshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME   = files
CC     = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
# -fsanitize=address

RM     = rm -fr


SRCS    = main.c ../manage_files/ft_append.c ../manage_files/change_stdout.c ../manage_files/change_stdint.c

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