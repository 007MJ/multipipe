#include "../../../include/includes.h"

t_cmd *initcmd(char *name, char *av)
{
    t_cmd   *new;

    new = malloc(sizeof(t_cmd) * 1);
    if (!new)
        return (NULL);
    new->av_cmd = newav(av);
    new->cmd_name = name;
    new->id = 0;
    new->type = type_of_cmd(name);
    new->pipes = 0;
    new->next = NULL;
    return (new);
}