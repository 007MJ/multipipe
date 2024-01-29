#ifndef MULIT_H
# define MULIT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct  s_cmd {
	int		index;
	pid_t	pid;
	int		**fds;
	char	**cmds;
	struct s_cmd *next;
} t_cmd;



#endif
