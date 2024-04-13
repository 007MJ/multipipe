/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:18:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/12 23:38:55 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"
void    ft_echo(char **av, bool newline)
{
    int i;

    i = 0;
    while (av[i] != NULL)
    {
        printf("%s", av[i]);
        if (av[i + 1] != NULL)
            printf(" ");
        i++;
    }
    if (newline == true)
        printf("\n");
}