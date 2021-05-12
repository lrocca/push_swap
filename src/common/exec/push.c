/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:24:11 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/12 18:07:36 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_ps *ps)
{
	t_node	*new;
	t_node	*last;

	if (!ps->b)
		return ;
	new = NULL;
	if (ps->b != ps->b->next)
	{
		new = ps->b->next;
		last = ps->b->prev;
		new->prev = last;
		last->next = new;
	}
	ft_nodepush_front(&ps->a, ps->b);
	ps->b = new;
}

void	pb(t_ps *ps)
{
	t_node	*new;
	t_node	*last;

	if (!ps->a)
		return ;
	new = NULL;
	if (ps->a != ps->a->next)
	{
		new = ps->a->next;
		last = ps->a->prev;
		new->prev = last;
		last->next = new;
	}
	ft_nodepush_front(&ps->b, ps->a);
	ps->a = new;
}
