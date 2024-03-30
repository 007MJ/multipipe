/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:53:15 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/29 16:27:17 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;

// 	i = 0;
// 	while (s1[i] && i < n)
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
// 		i++;
// 	}
// 	if (s2[i] == '\0' || i == n)
// 	{
// 		return (0);
// 	}
// 	else
// 		return (-s2[i]);
// }


int    type_of_cmd(char *s)
{
    if (ft_strncmp("|", s, ft_strlen("|")) == 0)
        return (PIPE);
    if (ft_strncmp(">>", s, ft_strlen(">>")) == 0)
        return (APPEND);
    if (ft_strncmp("<<", s, ft_strlen("<<")) == 0)
        return (HEREDOC);
    if (ft_strncmp(">", s, ft_strlen(">")) == 0)
        return (OUTPUT);
    if (ft_strncmp("<", s, ft_strlen("<")) == 0)
        return (INPUT);
    return (ARVG);
}