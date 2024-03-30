/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/30 14:48:47 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/includes.h"


t_cmd *trie_cmd(char **av)
{
    t_cmd   *head;
    t_cmd   *current;
    int     i;

    i = 0;
    current = NULL;
    head = NULL;
    while (av[i] != NULL)
    {
        if (head == NULL){
         printf("if 1\n");
            head = initcmd(av[i], av[i]);
            current = head;
        }
        else if (type_of_cmd(av[i]) <= 6){
            printf("else if 2!\n");
            while (current->next != NULL)
            {
                printf("...\n");
                current = current->next;
            }
            current->next = initcmd(av[i], av[i]);
            
        }else{
         printf("else 3\n");
            current->av_cmd = newcmds(current->av_cmd, av[i]);
        }
        i++;
    }
    // count number of PIPE IF THEY ARE 
    return (head);
}