#ifndef FILES_H
#define FILES_H

#include "unistd.h"
 #include <stdio.h>
#include <fcntl.h>



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