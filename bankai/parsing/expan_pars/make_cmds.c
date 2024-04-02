/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:37 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/01 23:31:19 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

void    print_cmd(t_cmd *head)
{
    t_cmd *current;

    current = head;
    printf("=============================================================\n");
    while (current != NULL)
    {
        printf("print cmd :: %s current->index %d current-nb_pipes %d ::: \n", current->cmd_name, current->index, current->nb_pipes);
        current = current->next;
    }
    printf("print :: end--\n");
    printf("=============================================================\n");
}
void    make_cmds(t_glob *shell_kai)
{
    char    **av;
    av = pars(shell_kai);
    if (av != NULL)
    {
        shell_kai->cmds = trie_cmd(av);
        // print_cmd(*shell_kai->cmds);
        setting_run(shell_kai);
    }
    // free av
}