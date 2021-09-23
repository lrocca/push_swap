/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:27:10 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/23 19:17:19 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	calc_b(t_ps *ps)
{
	t_node	*curr;
	int		size;
	int		ops;

	ops = 1;
	curr = ps->b->next;
	ps->b->ops_b = 0;
	size = stack_len(ps->b);
	while (curr != ps->b)
	{
		if (ops > size / 2)
			curr->ops_b = ops - size;
		else
			curr->ops_b = ops;
		ops++;
		curr = curr->next;
	}
}

static void	calc_a(t_ps *ps)
{
	t_node	*curr;
	t_node	*spot;
	int		size;
	int		ops;

	curr = ps->b;
	size = stack_len(ps->a);
	while (1)
	{
		ops = 0;
		spot = ps->a;
		while (size > 1)
		{
			if (spot->value > curr->value && spot->prev->value < curr->value)
				break ;
			else if (spot->prev->value > spot->value && \
			((curr->value > spot->value && curr->value > spot->prev->value) || \
			(curr->value < spot->value && curr->value < spot->prev->value)))
				break ;
			ops++;
			spot = spot->next;
		}
		if (ops > size / 2)
			curr->ops_a = ops - size;
		else
			curr->ops_a = ops;
		if (curr->next == ps->b)
			break ;
		curr = curr->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	calc_total_ops(int a, int b)
{
	if (a * b > 0)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	return (ft_abs(a) + ft_abs(b));
}

static int	calc_best(t_ps *ps)
{
	t_node	*curr;
	int		i;
	int		pos;
	int		min;
	int		ops;

	i = 1;
	pos = 0;
	curr = ps->b->next;
	min = calc_total_ops(ps->b->ops_a, ps->b->ops_b);
	while (curr != ps->b)
	{
		ops = calc_total_ops(curr->ops_a, curr->ops_b);
		if (ops < min)
		{
			min = ops;
			pos = i;
		}
		i++;
		curr = curr->next;
	}
	return (pos);
}

void	ft_sort_n(t_ps *ps)
{
	int		best;
	int		size;
	t_node	*curr;

	lis(ps);
	while (ps->b)
	{
		calc_b(ps);
		calc_a(ps);
		best = calc_best(ps);
		curr = ps->b;
		while (best--)
			curr = curr->next;
		if (curr->ops_a * curr->ops_b > 0)
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
		if (curr->ops_b < 0)
			while (curr->ops_b++)
				ft_exec(ps, RRB);
		else
			while (curr->ops_b--)
				ft_exec(ps, RB);
		if (curr->ops_a < 0)
			while (curr->ops_a++)
				ft_exec(ps, RRA);
		else
			while (curr->ops_a--)
				ft_exec(ps, RA);
		ft_exec(ps, PA);
	}
	size = 0;
	fix_a(ps, best, size, curr);
}
