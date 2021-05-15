/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:53:08 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/15 14:56:46 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_node	*ft_nodenew(int value, t_node *prev, t_node *next)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = prev;
	new->next = next;
	return (new);
}

void	ft_nodeadd_back(t_node **head, int value)
{
	t_node	*new;

	if (!*head)
	{
		new = ft_nodenew(value, NULL, NULL);
		*head = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		new = ft_nodenew(value, (*head)->prev, *head);
		(*head)->prev->next = new;
		(*head)->prev = new;
	}
}

void	ft_nodepush_front(t_node **head, t_node *new)
{
	if (!*head)
	{
		*head = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev->next = new;
		(*head)->prev = new;
		*head = new;
	}
}

void	ft_nodedelone(t_node *del)
{
	if (del)
		free(del);
}

void	ft_nodeclear(t_node **head)
{
	t_node	*curr;
	t_node	*next;

	if (head && *head)
	{
		curr = (*head)->next;
		while (curr != *head)
		{
			next = curr->next;
			ft_nodedelone(curr);
			curr = next;
		}
		ft_nodedelone(curr);
		*head = NULL;
	}
}
