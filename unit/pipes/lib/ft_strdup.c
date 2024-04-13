/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:10:18 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/12 23:47:35 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"
char    *ft_strdup(char *s)
{
    int     i;
    char    *n;
    
    i = 0;
    n = malloc(sizeof(char *) + ft_strlen(s) + 1);
    if (!n)
        return (NULL);
    while (s[i])
    {
        n[i] = s[i];
        i++;
    }
    n[i] = '\0';
    return (n);
}