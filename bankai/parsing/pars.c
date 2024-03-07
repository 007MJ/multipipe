/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/07 07:05:53 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

// quand il "" ou '' -> cela est comme un commande meme avec le space
// s'il n'a pas la fin du quote le programme ne devrait pas marche

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

char    **pars(t_glob *shell_kai)
{
    char **av;
    
    av = NULL;
    if (check_quote(shell_kai->input) == -1)
        return (NULL);
    replace_space(shell_kai->input);
    av = ft_split(shell_kai->input, ' ');
    put_back_space(av);
    remove_quote(av);
    return (av);
}
