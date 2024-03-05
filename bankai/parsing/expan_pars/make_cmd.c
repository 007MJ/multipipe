/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:37 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/04 19:21:17 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

int    type_of_cmd(char *s)
{
    int len;

    len = ft_stlen(s);
    if (ft_strncmp(s , ">", (size_t)len) == 0)
        return (OUTPUT);
    if (ft_strncmp(s , "<", (size_t)len) == 0)
        return (INPUT);
    if (ft_strncmp(s , "$", (size_t)len) == 0)
        return (DOLLAR);
    if (ft_strncmp(s , "$", (size_t)len) == 0)
        return (DOLLAR);
    if (ft_strncmp(s, "|", (size_t)len) == 0)
        return (PIPE);
    if (ft_strncmp(s, ">>", (size_t)len) == 0)
        return (APPEND);
    if (ft_strncmp(s, "<<", (size_t)len) == 0)
        return (HEREDOC);
    return (-1);
}

void    make_cmd(t_glob *shell_kai)
{
    char    **av;
    int     i;

    i = 0;
    av = pars(shell_kai);
    if (av != NULL)
    {
        while (av[i] != NULL)
        {
            printf("make_cmds : %s\n", av[i]);
            // type de cmd 
            // malloc la node 
            // add cmd name and cmd av pipes 
            i++;
        }
    }
}