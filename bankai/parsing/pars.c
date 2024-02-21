#include "../include/includes.h"

// quand il "" ou '' -> cela est comme un commande meme avec le space
// s'il n'a pas la fin du quote le programme ne devrait pas marche 

int cut(t_glob *shell_kai, char *s1)
{
    int i;

    i = 0;
    if (s1)
    {
        while (s1[i] != ' ')
        {

        }
    }
    return (i);
}

int number_av(t_glob *shell_kai)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (shell_kai->input[i] == ' ')
        i++;
    while (shell_kai->input[i] != '\0')
    {
        while (shell_kai->input[i] && shell_kai->input[i] != ' ')
            i++;
        if (shell_kai->input[i])
            count++;
        while (shell_kai->input[i] && shell_kai->input[i] == ' ')
            i++;
    }
    return (count);
}

void    pars(t_glob *shell_kai)
{
    int i;

    i = 0;
    if (shell_kai->input)
    {
        while (shell_kai->input[i] == ' ')
            i++;
        while (shell_kai->input[i] != '\0')
        {
            if (shell_kai->input[i] != '\'' || shell_kai->input[i] != '\"')
            {
                i += cut(shell_kai, &shell_kai->input[i]);
            }
            else if (shell_kai->input[i] == '|' || shell_kai->input[i] == '>' || shell_kai->input[i] == '<' || shell_kai->input[i] == '$')
                i += manage_sign();
            else
            {

            }
        }
    }
}

