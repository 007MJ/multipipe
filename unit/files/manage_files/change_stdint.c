#include "../../includes/global.h"

int change_stdint(t_files *file)
{
    int fd;

    if (file)
    {
        if (file->name)
        {
            if (file->name)
            {
                fd = open(file->name, O_RDONLY);
                if (fd > 0)
                {
                    dup2(fd, 0);
                    return (1);
                }
            }
            return (-1);
        }    
    }
    return (-1);
}