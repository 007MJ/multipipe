/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:32 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/16 16:02:47 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/global.h"


void ft_export(char **envp, char **vars, bool print)
{
    if (print)
        printEnvp(envp);
    else
        envp = addEnvp(envp, vars);
    (void)print;
    if (same_var_value(envp, vars[0]) == 1)
        printf("are the same %s \n", vars[0]);
//     for (int i = 0; envp[i] != NULL; i++)
//         printf("%s\n", envp[i]);
}