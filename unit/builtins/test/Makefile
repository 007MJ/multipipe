NAME    =     test
RM      =     rm -f
CCPP	=     gcc
CFLAG   =     -Wall -Werror -Wextra -g -fsanitize=address
SRC     =     main.c ../function/ft_echo.c ../function/ft_export.c ../function/utils/printEnvp.c ../function/utils/ft_strlen.c ../function/utils/addEnvp.c
 
OBJ     =     $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CCPP) $(OBJ) $(CFLAG) -o $@

%.o : %.cpp
	$(CCPP) $(CFLAG) -o $@ -c $^

clean :
	$(RM) $(OBJ) $(OBJSB)

fclean : clean
	$(RM) $(NAME)

re : fclean all
# -fsanitize=address