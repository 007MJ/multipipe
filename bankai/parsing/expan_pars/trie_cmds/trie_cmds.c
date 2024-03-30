/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/30 16:50:51 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/includes.h"

void    count_pipe(t_cmd **head, char **av)
{
    if (!head)
        return ;
    t_cmd   *current;
    int     i;
    int     count;

    i = 0;
    count = 1;
    current = *head;
    while (av[i])
    {
        if (type_of_cmd(av[i]) == 1)
            count++;
        i++;
    }
    while (current != NULL){
        current->nb_pipes = count;
        current->pipes = init_pipes(count);
        current = current->next;
    }
}

t_cmd **trie_cmd(char **av)
{
    t_cmd   **head;
    t_cmd   *current;
    int     i;
    int     index;

    i = 0;
    index = 0;
    current = NULL;
    head = NULL;
    while (av[i] != NULL)
    {
        if (head == NULL){
            head = (t_cmd **)malloc(sizeof(t_cmd**));
            *head = initcmd(av[i], av[i]);
            current = *head;
            current->index = index;
            index++;
        }
        else if (type_of_cmd(av[i]) <= 6){
            printf("else if 2!\n");
            while (current->next != NULL)
            {
                printf("...\n");
                current = current->next;
            }
            current->next = initcmd(av[i], av[i]);
            current->index = index;
            index++;
            
        }else{
         printf("else 3\n");
            current->av_cmd = newcmds(current->av_cmd, av[i]);
        }
        i++;
    }
    // count number of PIPE IF THEY ARE :: DONE
    // count l'index 
    // init pipe
    // return un double pointeur cmds !
    return (count_pipe(head, av), head);
}