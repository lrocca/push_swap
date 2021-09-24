/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:27:10 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/24 16:56:55 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_r(t_ps *ps, t_node *curr)
{
	while (curr->ops_a && curr->ops_b)
	{
		if (curr->ops_a > 0)
		{
			curr->ops_a--;
			curr->ops_b--;
			ft_exec(ps, RR);
		}
		else
		{
			curr->ops_a++;
			curr->ops_b++;
			ft_exec(ps, RRR);
		}
	}
}

static void	exec_b(t_ps *ps, t_node *curr)
{
	if (curr->ops_b < 0)
		while (curr->ops_b++)
			ft_exec(ps, RRB);
	else
		while (curr->ops_b--)
			ft_exec(ps, RB);
}

static void	exec_a(t_ps *ps, t_node *curr)
{
	if (curr->ops_a < 0)
		while (curr->ops_a++)
			ft_exec(ps, RRA);
	else
		while (curr->ops_a--)
			ft_exec(ps, RA);
}

static void	fix_a(t_ps *ps, int operations, int size, t_node *spot)
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
	int		best;
	int		size;
	t_node	*curr;

	ft_lis(ps);
	while (ps->b)
	{
		best = calc_best(ps);
		curr = ps->b;
		while (best--)
			curr = curr->next;
		if (curr->ops_a * curr->ops_b > 0)
			exec_r(ps, curr);
		exec_b(ps, curr);
		exec_a(ps, curr);
		ft_exec(ps, PA);
	}
	size = 0;
	fix_a(ps, best, size, curr);
}
