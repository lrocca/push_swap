/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:24:45 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/17 20:30:16 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_ps *ps)
{
	if (ps->a->value > ps->a->prev->value)
	{
		if (ps->a->value < ps->a->next->value)
			ft_exec(ps, RRA);
		else
			ft_exec(ps, RA);
	}
	else
		ft_exec(ps, SA);
	if (!ft_issorted(ps->a))
		return (ft_sort_three(ps));
}
