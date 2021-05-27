/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:53:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/27 18:56:08 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_indices(t_node *head)
{
	t_node	*curr;

	head->index = -1;
	curr = head->next;
	while (curr != head)
	{
		curr->index = -1;
		curr = curr->next;
	}
}

static t_node	*next_min(t_node *head)
{
	t_node	*min;
	t_node	*curr;

	min = head;
	while (1)
	{
		if (min->index == -1)
			break ;
		min = min->next;
		if (min == head)
			return (NULL);
	}
	curr = min->next;
	head = min;
	while (min && curr != head)
	{
		if (curr->index == -1 && curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	if (min->index != -1)
		return (NULL);
	return (min);
}

void	set_indices(t_ps *ps)
{
	t_node	*head;
	t_node	*min;
	int		i;

	i = 0;
	init_indices(ps->a);
	head = ps->a;
	while (1)
	{
		min = next_min(head);
		if (!min)
			break ;
		head = min->next;
		min->index = i;
		i++;
	}
}
