/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/08 16:14:16 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

int is_quote(char *input)
{
    int one_q;
    int two_q;
    int i;

    i = 0;
    one_q = 0;
    two_q = 0;
    while (input[i] && input[i] != '\0')
    {
        if (input[i] == '\'')
            one_q++;
        if (input[i] == '\"')
            two_q++;
        i++;
    }
    if (one_q % 2 == 0 || two_q  % 2 == 0)
        return (1);
    return (-1);
}

int trie_cmd(t_cmd **cmds, char *av)
{
    // tu dois faire en sorte   que seulement ceux qui on des quote sont prise en charge par la function
    if (is_quote(av) == 1)
        remove_first_quote(av, cmds);
    (void)cmds;
    // tu remove les first quote du mots et tu colle le mots si nécessaire
    // si le mot est un sign tu regarde dépendamment c'est arguments
    // si le mot contient que des signe tu va le split seulement s'il ne pas dans des quotes 
    return (1);
}