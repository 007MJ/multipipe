/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:00:58 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/12 23:46:56 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"


void	append(t_cmd **head, t_cmd *node)
{
	if ((*head) == NULL)
	{
		*head = node;
		return ;
	}
	t_cmd *current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
}