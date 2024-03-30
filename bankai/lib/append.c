/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:00:58 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/03/30 16:13:11 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"


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