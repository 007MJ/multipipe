/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:53:15 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/07 17:24:46 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

int len_new_str(char *s1, int *i)
{
    int len;
    
    len = ft_strlen(s1);
    if (s1[*i] == '\"' || s1[*i] == '\'')
    {
        *i += 1;
        len--;
    }
    return (len);
}
char *is_quote_remove(char *s1, char *s2)
{
    int     i;
    int     j;
    int     len;
    
    i = 0;
    j = 0;
    if (s1)
    {
        len = len_new_str(s1, &i);
        len += i;
        s2 = ft_calloc(len, sizeof(char *));
        printf("len : %d \n", len);
        printf("iterater : %d \n", i);
        while (s1[i] && i < len - 1 && s1[i] != '\0')
        {
                s2[j] = s1[i];
            printf("-- %c and %c --\n", s2[j], s1[i]);
            i++;
            j++;
        }
        s2[j] = '\0';
        printf(" is quote remove%s \n", s2);
        return (s2);
    }
    return (NULL);
}

int    type_of_cmd(char *s)
{
    int len;
    char    *s2;
    
    s2 = NULL;
    len = ft_strlen(s);
    printf(" commande %s ]\n", is_quote_remove(s, s2));
    return (ARVG);
}