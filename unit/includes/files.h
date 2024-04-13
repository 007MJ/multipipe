#ifndef FILES_H
#define FILES_H

#include "global.h"
typedef struct s_glob t_glob;

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