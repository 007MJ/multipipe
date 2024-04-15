#ifndef UNIT_H
#define UNIT_H

#include "global.h"


typedef struct s_glob t_glob;
typedef struct s_files t_files;
void    is_change_std(t_files *files);
int     unit(t_glob *shell);
void    which_cmd(t_cmd *current);

#endif