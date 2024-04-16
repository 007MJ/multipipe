#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// echo function
void ft_echo(char **av, bool newline);

//export funcrion 
void ft_export(char **envp, char **argv, bool print);

// utils function 
void printEnvp(char **envp);
char **addEnvp(char **envp, char **argv);
int ft_strlen(char *);

#endif