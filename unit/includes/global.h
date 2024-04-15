#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "pipes.h"
#include "builtins.h"
#include "files.h"
#include "unit.h"

# define PIPE       1
# define OUTPUT     2
# define INPUT      3
# define APPEND     4
# define DOLLAR     5
# define HEREDOC    6
# define ARVG       7
# define BUILT      8


typedef struct s_glob
{
	char    **envp;
    char    *input;
	int     **pipes;
	int		nb_cmds;
	int		nb_pipes;
	int		_return;
    int     on;

	t_cmd	*cmds;
	t_files *files;
}t_glob;



# endif