/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:24:42 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/17 20:36:09 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_ps *ps)
{
	int	len;

	len = ps->len;
	while (len-- > 3 && !ft_issorted(ps->a))
		ft_exec(ps, PB);
	if (!ft_issorted(ps->a))
		ft_sort_three(ps);
	while (ps->b)
	{
		if (ps->b->value > ps->b->next->value)
			ft_exec(ps, RB);
		if (ps->b->value > ps->a->prev->value)
		{
			ft_exec(ps, PA);
			ft_exec(ps, RA);
		}
		else if (ps->b->value < ps->a->value)
			ft_exec(ps, PA);
		else if (ps->b->value < ps->a->prev->value && ps->b->value > ps->a->next->value)
		{
			ft_exec(ps, RRA);
			ft_exec(ps, PA);
			ft_exec(ps, RA);
			ft_exec(ps, RA);
		}
		else if (ps->b->value > ps->a->value && ps->b->value < ps->a->next->value)
		{
			ft_exec(ps, RA);
			ft_exec(ps, PA);
			ft_exec(ps, RRA);
		}
		else
			break ;
	}
}
