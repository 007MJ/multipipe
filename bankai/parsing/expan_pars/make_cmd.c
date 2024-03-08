/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:37 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/08 00:24:39 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

void    make_cmd(t_glob *shell_kai)
{
    char    **av;
    t_cmd   **cmds;
    int     i;

    i = 0;
    cmds = NULL;
    av = pars(shell_kai);
    if (av != NULL)
    {
        while (av[i] != NULL)
        {
            printf("make_cmds : %s | Type cmd: %d \n", av[i], type_of_cmd(av[i]));
            i += trie_cmd(cmds, av[i]);
        }
        shell_kai->cmds = cmds;
    }
}