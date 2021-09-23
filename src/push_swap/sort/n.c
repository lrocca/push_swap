/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:27:10 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/23 16:35:44 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_a(t_ps *ps, int operations, int size, t_node *spot)
{
	spot = ps->a;
	operations = 0;
	while (spot->value > spot->prev->value)
	{
		operations++;
		spot = spot->next;
	}
	size = operations;
	while (spot != ps->a)
	{
		size++;
		spot = spot->next;
	}
	if (operations > size / 2)
	{
		operations = size - operations;
		while (operations--)
			ft_exec(ps, RRA);
	}
	else
		while (operations--)
			ft_exec(ps, RA);
}

void	ft_sort_n(t_ps *ps)
{
	int		operations;
	int		size;
	t_node	*spot;

	lis(ps);
	while (ps->b)
	{
		operations = 0;
		spot = ps->a;
		while (1)
		{
			if (spot->value > ps->b->value && spot->prev->value < ps->b->value)
				break ;
			else if (spot->prev->value > spot->value && \
			((ps->b->value > spot->value && ps->b->value > spot->prev->value) || \
			(ps->b->value < spot->value && ps->b->value < spot->prev->value)))
				break ;
			operations++;
			spot = spot->next;
		}
		size = operations;
		while (spot != ps->a)
		{
			size++;
			spot = spot->next;
		}
		if (operations > size / 2)
		{
			operations = size - operations;
			while (operations--)
				ft_exec(ps, RRA);
		}
		else
			while (operations--)
				ft_exec(ps, RA);
		ft_exec(ps, PA);
	}
	fix_a(ps, operations, size, spot);
}
