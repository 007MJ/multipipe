#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>


// echo function

typedef struct s_built
{
    char    *name;
    char    **envp;
    char    **arv;
    bool    is_var;
} t_built;

void ft_echo(char **av, bool newline);

//export funcrion 
void ft_export(char **envp, char **argv, bool);

// utils function 
void printEnvp(char **envp);
char **addEnvp(char **envp, char **argv);
int ft_strlen_utils(char *);
int same_varibale(char **envp, char *var);
int same_var_value(char **envp, char *var);
int is_add(char **envp, char *var, int kv);

#endif