/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 06:17:46 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/07 07:05:31 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

int len_space(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if(s[i] == 30)
            count++;
        i++;
    }
    return (count);
}

char    *put_space(char *s)
{
    int     i;
    int     j;
    char    *s1;
    
    i = 0;
    j = 0;
    s1 = ft_calloc(ft_strlen(s) + len_space(s) , sizeof(char *));
    if (!s1)
        return (NULL);
    while (s[i])
    {
        printf(" space : -- %c --\n", s1[i]);
        if (s[i] == 30)
        {
            printf("30");
            s1[i] = 32;
        }
        else
            s1[i] = s[i];
        i++;
    }
    free(s);
    s1[i] = '\0';
    return (s1);
}

void    put_back_space(char **s1)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i][0] == '\"' || s1[i][0] == '\'')
           s1[i] = put_space(s1[i]);
         i++;
    }
}