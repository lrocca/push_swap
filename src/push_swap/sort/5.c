/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:24:42 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/25 16:49:50 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_stacks(t_ps *ps)
{
	if (ps->b->value > ps->b->next->value)
		ft_exec(ps, RB);
	while (ps->b)
	{
		if ((ps->a->value > ps->b->value && ps->a->prev->value < ps->b->value) \
		|| (ps->a->prev->value > ps->a->value && \
		(ps->a->value > ps->b->value || ps->a->prev->value < ps->b->value)))
			ft_exec(ps, PA);
		ft_exec(ps, RA);
	}
	while (ps->a->value > ps->a->prev->value)
		ft_exec(ps, RA);
}

void	ft_sort_five(t_ps *ps)
{
	int	len;

	len = ps->len;
	while (len-- > 3 && !ft_issorted(ps->a))
		ft_exec(ps, PB);
	if (!ft_issorted(ps->a))
		ft_sort_three(ps);
	if (ps->b)
		merge_stacks(ps);
}
