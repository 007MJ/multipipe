#include "../../../include/includes.h"

int sizecmds(char **cmds, char *n)
{
    int i;

    i = 0;
    if (cmds)
        while (cmds[i] != NULL)
            i++;
    if (n)
        i++;
    return (i);
}
