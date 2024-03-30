/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/30 04:13:35 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

char **newav(char *av)
{
    char    **v;
    int     i;
    int     j;

    j = 0;
    i = 0;
    v = malloc(sizeof(char *) * 2);
    if (!v)
        return (NULL);
    v[i] =  malloc(sizeof(char *) * (ft_strlen(av) + 1));
    while (av[j] != '\0')
    {
        v[i][j] = av[j];
        j++;
    }
    v[i][j] = '\0';
    v[i + 1] = NULL;
    return (v);  
}

t_cmd *initcmd(char *name, char *av)
{
    t_cmd   *new;

    new = malloc(sizeof(t_cmd) * 1);
    if (!new)
        return (NULL);
    new->av_cmd = newav(av);
    new->cmd_name = name;
    new->id = 0;
    new->type = type_of_cmd(name);
    new->pipes = 0;
    new->next = NULL;
    return (new);
}

int sizecmds(char **cmds, char *n)
{
    int i;

    i = 0;
    if (cmds)
        while (cmds[i] != NULL)
            i++;
    if (n)
        i++;
    return (i);
}

char *    allocatecpy( char *src)
{
    // use ft_strdup();
    int i;
    char *new;

    i = 0;
    new = malloc(sizeof(char *) * ft_strlen(src) + 1);
    if (!new)
        return NULL;
    while (src[i] != '\0')
    {
        new[i] = src[i];
        i++;
    }
    new[i] = '\0';
    return new;
}

void	ft_cpycmds(char **new, char **olds, const char *n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (olds)
    {
        while (olds[i] != NULL)
        {
            new[i] = allocatecpy(olds[i]);
            i++;   
        }
        free(olds);
    }
    new[i] = allocatecpy((char *)n);
}

char **newcmds(char **olds, char *n)
{
    char **new;
    int size;

    size = sizecmds(olds, n);
    new = malloc(sizeof(char *) * (size + 1));
    new[size] = NULL;
    if (!new)
        return (NULL);
    ft_cpycmds(new, olds, n);
    return (new);
}

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
    return (head);
}