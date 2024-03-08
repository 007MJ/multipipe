/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/08 14:59:19 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"


int trie_cmd(t_cmd **cmds, char *av)
{
    if (check_quote(av) != -1)
        remove_first_quote(av, cmds);
    (void)cmds;
    // tu remove les first quote du mots et tu colle le mots si nécessaire
    // si le mot est un sign tu regarde dépendamment c'est arguments
    // si le mot contient que des signe tu va le split seulement s'il ne pas dans des quotes 
    return (1);
}