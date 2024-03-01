/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:55 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/01 16:39:21 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int space_words(char *input)
{
    int i;

    i = 0;
    while (input[i] != ' ' && input[i] != '\0' && input[i] != '\"' && input[i] != '\"')
        i++;
    return (i);
}
char  *manage_words(int *i, char *input)
{
    char    *s1; 
    
    // printf("[Manage words] Start -- pars -- %s  .....\n", input);
    s1 = ft_calloc(space_words(input), sizeof(char *));
    if (s1)
    {
        while (input[*i] && input[*i] != '\0' && input[*i] != ' ' && input[*i] != '\"' && input[*i] != '\"')
        {
            // printf("while words :.. \n");
            s1[*i] = input[*i];
            *i +=1;
        }
        s1[*i] = '\0';
        // printf("End pars -- %s -- \n", s1);
    }
    while (input[*i] == ' ')
    {
        // printf("while spaec .. \n");
        *i += 1;
    }
    // printf ("return  i %d \n", i);
    return (s1);
}