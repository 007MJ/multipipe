/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:37 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/30 04:25:04 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

void    print_cmd(t_cmd *head)
{
    t_cmd *current;

    current = head;
    while (current != NULL)
    {
        printf("print cmd :: %s\n", current->cmd_name);
        current = current->next;
    }
    printf("print :: end--\n");
}
void    make_cmd(t_glob *shell_kai)
{
    char    **av;
    av = pars(shell_kai);
    if (av != NULL)
    {
          shell_kai->cmds = trie_cmd(av);
        print_cmd(shell_kai->cmds);
    }
}