#include "../include/includes.h"


int   *array_child_ids(int nb_id)
{
    int     *waitchild;

    waitchild = (pid_t *)malloc(sizeof(pid_t) * (nb_id));
    if (!waitchild)
    {
        *waitchild  = -1;
        return (waitchild);
    }
    return (waitchild);
}