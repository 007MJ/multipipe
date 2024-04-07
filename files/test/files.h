#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_files 
{
	char	*name;
	char	**agrv;
	struct	s_file *next;
}t_files;


#endif