/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/02/25 20:00:48 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

// quand il "" ou '' -> cela est comme un commande meme avec le space
// s'il n'a pas la fin du quote le programme ne devrait pas marche 

int number_av(t_glob *shell_kai)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (shell_kai->input[i] == ' ')
        i++;
    while (shell_kai->input[i] != '\0')
    {
        while (shell_kai->input[i] && shell_kai->input[i] != ' ')
            i++;
        if (shell_kai->input[i])
            count++;
        while (shell_kai->input[i] && shell_kai->input[i] == ' ')
            i++;
    }
    return (count);
}

char   **pars(t_glob *shell_kai)
{
    char    **av;
    int     ac;
    int     i;
    int     j;

    ac = number_av(shell_kai);
    j = 0;
    i = 0;
    while (shell_kai->input[i] == ' ' && shell_kai->input[i] != '\0')
        i++;
    if(check_quote(&shell_kai->input[i]) == -1)
        return (NULL);
    av = ft_calloc(ac, sizeof(char **));
    av[ac] = NULL;
    while (shell_kai->input[i] != '\0')
    {
        if (shell_kai->input[i] == '|' || shell_kai->input[i] == '>' || shell_kai->input[i] == '<' || shell_kai->input[i] == '$')
            i += manage_sign(av[j], &shell_kai->input[i]);
        if (shell_kai->input[i] == '\'' || shell_kai->input[i] == '\"')
            i += manage_quote(av[j], shell_kai->input[i], &shell_kai->input[i]);
        else
            i += manage_words(av[j], &shell_kai->input[i]);
        j++;
    }
    return (av);
}

