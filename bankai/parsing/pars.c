/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/04 18:35:00 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

// quand il "" ou '' -> cela est comme un commande meme avec le space
// s'il n'a pas la fin du quote le programme ne devrait pas marche 

char    **pars(t_glob *shell_kai)
{
    char **av;
    
    if (check_quote(shell_kai->input) == -1)
        return (NULL);
    manage_quote(shell_kai->input);
    av = ft_split(shell_kai->input, ' ');
    return (av);
}
