/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/01 16:41:22 by mnshimiy         ###   ########.fr       */
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
    av = ft_calloc(ac + 1, sizeof(char **));
    printf(" ac :: = %d\n", ac);
    av[ac] = NULL;
    while (shell_kai->input[i] != '\0'  || j < ac)
    {
        printf(" j = : %d\n", j);
        if (shell_kai->input[i] == '|' || shell_kai->input[i] == '>' || shell_kai->input[i] == '<' || shell_kai->input[i] == '$')
            av[j] = manage_sign(&i, &shell_kai->input[i]);
        if (shell_kai->input[i] == '\'' || shell_kai->input[i] == '\"')
          av[j] = manage_quote(&i, shell_kai->input[i], &shell_kai->input[i]);
        else
           av[j] = manage_words(&i, &shell_kai->input[i]);
        j++;
    }
    for (int i = 0; av[i] != NULL; i++)
        printf(" pars : %s\n", av[i]);
    return (av);
}

