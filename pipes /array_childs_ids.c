#include "test/pipes.h"


int   *array_child_ids(int nb_id)
{
    int     *waitchild;

    waitchild = NULL;
    if (nb_id == 0)
        return (*waitchild = 0 , waitchild);
    waitchild = (pid_t *)malloc(sizeof(pid_t) * (nb_id));
    if (!waitchild)
    {
        *waitchild  = 0;
        return (waitchild);
    }
    return (waitchild);
}