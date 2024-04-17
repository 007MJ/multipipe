/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:32 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/17 18:07:20 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/global.h"


void ft_export(char **envp, char **vars, bool print)
{
    char **tmp;

    tmp = NULL;
    if (print)
        printEnvp(envp);
    else
    {
        tmp = check_duplicate(vars);
        envp = addEnvp(envp, tmp);
        // free_str(tmp);
    }
    // for (int i = 0; tmp[i] != NULL; i++)
    //     printf("%s -- %d \n ", tmp[i], i);
    // (void)print;
    // if (same_var_value(envp, vars[0]) == 1)
    //     printf("are the same %s \n", vars[0]);
    if (envp)
    {
        printf("= ============================make the difference========================================\n");
        for (int i = 0; envp[i] != NULL; i++)
            printf("%s\n", envp[i]);
        printf("= ====================================================================\n");
    }else 
        printf(" envp don't here \n");
}