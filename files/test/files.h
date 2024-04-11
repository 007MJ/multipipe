#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define HEREDOC    6 
# define APPEND     4 
typedef struct s_cmd t_cmd; 
typedef struct s_files	t_files; 


typedef struct s_glob
{
	char    **envp;
    char    *input;
	int     **pipes;
	int		_return;
    int     on;

	t_cmd	*cmds;
	t_files *files;

}t_glob;


typedef	struct	s_files 
{
	int		type;
	char	*name;
	char	*agrv;
	struct	s_files *next;
}t_files;




int	ft_append(t_files *files);
int	change_stdout(t_files *files);	
int	change_stdint(t_files *files);


#endif