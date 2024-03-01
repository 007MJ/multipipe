/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:37 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/01 16:38:19 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

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
            i++;
        }
    }
}