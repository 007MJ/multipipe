/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:32 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/27 13:00:13 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../test/include.h"


void ft_export(char **envp, char **vars, bool print)
{
    if (print)
        printEnvp(envp);
    else
        envp = addEnvp(envp, vars);
    for (int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);
}