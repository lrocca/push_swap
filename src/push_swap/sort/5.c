/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:24:42 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/25 20:08:14 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_nodemin(t_node *head)
{
	t_node	*curr;
	t_node	*min;

	min = head;
	curr = head->next;
	while (curr != head)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

void	ft_sort_five(t_ps *ps)
{
	t_node	*min;
	char	*op;
	int		len;

	len = ps->len;
	while (len-- > 3 && !ft_issorted(ps->a))
	{
		min = ft_nodemin(ps->a);
		op = RA;
		if (!(min == ps->a || min == ps->a->next \
		|| (ps->len == 5 && min == ps->a->next->next)))
			op = RRA;
		while (ps->a != min)
			ft_exec(ps, op);
		ft_exec(ps, PB);
	}
	if (!ft_issorted(ps->a))
		ft_sort_three(ps);
	while (ps->b)
		ft_exec(ps, PA);
}
