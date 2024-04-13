#include "../includes/global.h"

void    is_change_std(t_files *files)
{
    if (files)
    {
        if (files->type == APPEND)
            ft_append(files);
        if (files->type == INPUT)
            change_stdint(files);
        if (files->type == OUTPUT)
            change_stdout(files);

    }
}