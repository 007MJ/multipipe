/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:43:54 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/07 16:09:19 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

char    *if_remove(char *s1)
{
    char    *s;
    int     len;
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    len = ft_strlen(s1);
    s = NULL;
    if (s1 && (s1[0] == '\"' || s1[0] == '\''))
    {
        s = ft_calloc(len + 1, sizeof(char *));
        i++;
        while (s1[i] && i < len - 1)
        {
            s[j] = s1[i];
            printf(" -- %c -- \n", s[j]);
            i++;
            j++;
        }
        free(s1);
        s[j] = '\0';
        return (s);
    }
    return (s1);
}

void    remove_quote(char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        av[i] = if_remove(av[i]);
        printf("-- new cmd  %s -- \n", av[i]);
        i++;
    }
}