/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:53:08 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/11 19:45:04 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_node	*ft_nodenew(t_node *prev, t_node *next, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->prev = prev;
	new->next = next;
	new->value = value;
	return (new);
}

/*
** `if head`:
** - first.prev = new
** - last.next = new
*/
void	ft_nodeadd_back(t_node **head, int value)
{
	t_node	*new;

	if (!*head)
	{
		new = ft_nodenew(NULL, NULL, value);
		*head = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		new = ft_nodenew((*head)->prev, *head, value);
		(*head)->prev = new;
		new->prev->next = new;
	}
}
