/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/02 00:56:03 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/includes.h"


// void    print_cmd(t_cmd *head)
// {
//     t_cmd *current;

//     current = head;
//     printf("=============================================================\n");
//     while (current != NULL)
//     {
//         printf("print cmd :: %s current->index %d current-nb_pipes %d ::: \n", current->cmd_name, current->index, current->nb_pipes);
//         current = current->next;
//     }
//     printf("print :: end--\n");
//     printf("=============================================================\n");
// }

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
    // printf(";;;;;;; %d \n", count);
    while (current != NULL)
    {
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
            (*head)->index = index;
            current = *head;
            // printf("if -> ::  ");
            // printf("current_cmd : %s current->av_cmd %s :: and current->index %d :\n", current->cmd_name, (*current->av_cmd), current->index);
            index++;
        }
        else if (type_of_cmd(av[i]) == 1){
            // printf("else if 2! -> :: ");
            // current = current->next;
            i++;
            current->next = initcmd(av[i], av[i]);
            current->next->index = index;
            // printf("current_cmd : %s current->av_cmd %s :: and current->index %d :\n", current->cmd_name, (*current->av_cmd), current->index);
            index++;
            
        }else{
        //  printf("else 3 -> ::");
        //  printf("current_cmd : %s current->av_cmd %s :: and current->index %d :\n", current->cmd_name, (*current->av_cmd), current->index);
            current->av_cmd = newcmds(current->av_cmd, av[i]);
        }
        i++;
    }
    // count number of PIPE IF THEY ARE :: DONE
    // count l'index 
    // init pipe
    // return un double pointeur cmds !
    // ,
    // print_cmd(*head);
    return (count_pipe(head, av), head);
}