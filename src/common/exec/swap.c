/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:17:02 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/28 18:33:20 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_ps *ps)
{
	t_node	*first;
	t_node	*new;
	t_node	*last;

	if (!ps->a || ps->a == ps->a->next)
		return ;
	first = ps->a;
	last = ps->a->prev;
	new = ps->a->next;
	new->next->prev = first;
	last->next = new;
	first->prev = new;
	first->next = new->next;
	new->next = first;
	new->prev = last;
	ps->a = new;
}

void	sb(t_ps *ps)
{
	t_node	*first;
	t_node	*new;
	t_node	*last;

	if (!ps->b || ps->b == ps->b->next)
		return ;
	first = ps->b;
	last = ps->b->prev;
	new = ps->b->next;
	new->next->prev = first;
	last->next = new;
	first->prev = new;
	first->next = new->next;
	new->next = first;
	new->prev = last;
	ps->b = new;
}

void	ss(t_ps *ps)
{
	sa(ps);
	sb(ps);
}
