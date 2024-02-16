#include "../include/includes.h"


static char    *_without_path(char *s1, char *s2)
{
    int    i;

    i = 0;
    if (s1 && s2)
    {
        while ((s1[i] == s2[i]) && (s1[i] != '\0') && s2[i] != '\0')
            i++;
        return (s2 + i);
    }
    return (NULL);
}

char    *get_envp_path(char **envp)
{
    int        index;

    index = 0;
    while (envp[index])
    {
        if (ft_strncmp("PATH=", envp[index], ft_strlen("PATH=")) == 0)
            return (_without_path("PATH=", envp[index]));
        index++;
    }
    return (NULL);
}

static char    *_check_absolute_path(char *cmd)
{
    if (cmd[0] == '/')
        if (access(cmd, F_OK) == 0)
            return (cmd);
    return (NULL);
}

char    *get_cmd_path(char *path, char *cmd)
{
    char    **sub_paths;
    int 	i;
    char    *cmd_path;

    cmd_path = _check_absolute_path(cmd);
    if (cmd_path != NULL)
        return (cmd_path);
    sub_paths = ft_split(path, ':');
    i = 0;
    while (sub_paths[i])
    {
        cmd_path = ft_strjoin(sub_paths[i], "/"); // TODO: Caching system (key -> value)
        cmd_path = ft_strjoin(cmd_path, cmd);
        if (access(cmd_path, F_OK) == 0)
            return (free_str(sub_paths), cmd_path);
        free(cmd_path);
        i++;
    }
    free_str(sub_paths);
    return (NULL);
}