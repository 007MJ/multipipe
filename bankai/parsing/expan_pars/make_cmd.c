/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:37 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/07 15:59:15 by mnshimiy         ###   ########.fr       */
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
            printf("make_cmds : %s Type cmd: %d \n", av[i], type_of_cmd(av[i]));
            // pars/more pour le " remove single quoi whereve && <echo<"
            // type de cmd 
            // malloc la node 
            // add cmd name and cmd av pipes
            i++;
        }
    }
}