/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_first_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:38:49 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/08 16:10:28 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

char quote_on_plist(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '\"' || s[i] == '\'')
            return (s[i]);
        i++;
    }
    return (0);
}
int is_sign_quoted(char *s)
{
    (void)s;
    return (0);
}
char *join_word(char **tab)
{
    int     i;
    char    *s;
    i = 0;
    s = NULL;
    while (tab[i + 1] != NULL)
    {
        printf("join -- %s --\n", s);
        s = ft_strjoin(tab[i], tab[i + 1]);
        i++;
    }
    return (s);
}
int remove_first_quote(char *s, t_cmd **cmds)
{
    (void)cmds;
    char  **tab;
    char   *cmd;
    printf("-- %c --\n", quote_on_plist(s));
    tab = ft_split(s, quote_on_plist(s));
    printf("split...\n");
    for (int i = 0; tab[i] != NULL; i++)
    {
        printf("split -- %s -- \n", tab[i]);
    }
    printf("split end\n");
    cmd = join_word(tab);
    printf("-- %s cmd --\n", cmd);
    return (1);
}