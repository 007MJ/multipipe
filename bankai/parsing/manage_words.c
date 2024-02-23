/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:55 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/02/23 14:57:33 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int space_words(char *input)
{
    int i;

    i = 0;
    while (input[i] != ' ' && input[i] != '\0')
        i++;
    return (i);
}
int  manage_words(char *s1, char *input)
{
    int i;

    i = 0;
    printf("[Manage words] Start -- pars -- %s  .....\n", input);
    s1 = ft_calloc(space_words(input), sizeof(char *));
    if (s1)
    {
        while (input[i] && input[i] != '\0' && input[i] != ' ')
        {
            printf("while words :.. \n");
            s1[i] = input[i];
            i++;
        }
        s1[i] = '\0';
        printf("End pars -- %s -- \n", s1);
    }
    while (input[i] == ' ')
    {
        printf("while spaec .. \n");
        i++;
    }
    printf ("return  i %d \n", i);
    return (i);
}