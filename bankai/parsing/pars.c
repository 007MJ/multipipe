/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/29 16:32:14 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

// quand il "" ou '' -> cela est comme un commande meme avec le space
// s'il n'a pas la fin du quote le programme ne devrait pas marche


char    **pars(t_glob *shell_kai)
{
    char **av;
    
    av = NULL;
    if (check_quote(shell_kai->input) == -1)
        return (NULL);
    // printf("%s\n", shell_kai->input);
    replace_space(shell_kai->input);
    av = ft_split(shell_kai->input, ' ');
    put_back_space(av);
    // remove_quote(av);
    return (av);
}
