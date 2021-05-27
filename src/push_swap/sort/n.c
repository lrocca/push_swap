/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:27:10 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/27 19:26:48 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_if(t_ps *ps, int i)
{
	if (((ps->a->index >> i) & 1) == 1)
		ft_exec(ps, RA);
	else
		ft_exec(ps, PB);
}

static void	loop(t_ps *ps, int i)
{
	int	len;

	len = ps->len;
	while (len--)
		move_if(ps, i);
	while (ps->b)
		ft_exec(ps, PA);
}

void	ft_sort_n(t_ps *ps)
{
	int	i;

	i = 0;
	while (1)
	{
		loop(ps, i);
		if (ft_issorted(ps->a))
			break ;
		i++;
	}
}
