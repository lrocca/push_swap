/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:16:52 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/24 14:50:03 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	is_spot(t_node *curr, t_node *spot)
{
	return (
		(spot->value > curr->value && spot->prev->value < curr->value) || \
		(spot->prev->value > spot->value && \
			((curr->value > spot->value && curr->value > spot->prev->value) || \
			(curr->value < spot->value && curr->value < spot->prev->value))));
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
		while (size > 1 && !is_spot(curr, spot))
		{
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

static int	calc_total_ops(int a, int b)
{
	if (a * b <= 0)
		return (ft_abs(a) + ft_abs(b));
	if (ft_abs(a) > ft_abs(b))
		return (ft_abs(a));
	else
		return (ft_abs(b));
}

int	calc_best(t_ps *ps)
{
	t_node	*curr;
	int		i;
	int		pos;
	int		min;
	int		ops;

	calc_b(ps);
	calc_a(ps);
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
