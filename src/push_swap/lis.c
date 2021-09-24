/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:05:25 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/24 17:15:28 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_loop(t_lis *lis, int i)
{
	int	j;

	if (lis->stack[i] > lis->stack[lis->array[lis->length]])
	{
		lis->length++;
		lis->array[lis->length] = i;
		lis->trace[lis->array[lis->length]] = lis->array[lis->length - 1];
	}
	else if (lis->stack[i] < lis->stack[lis->array[0]])
		lis->array[0] = i;
	else
	{
		j = 0;
		while (j < lis->length + 1)
		{
			if (lis->stack[i] < lis->stack[lis->array[j]])
			{
				lis->array[j] = i;
				lis->trace[lis->array[j]] = lis->array[j - 1];
				break ;
			}
			j++;
		}
	}
}

static void	lis_reverse(t_lis *lis)
{
	int	i;
	int	j;

	i = lis->length;
	j = lis->array[lis->length];
	while (i >= 0)
	{
		lis->array[i--] = j;
		j = lis->trace[j];
	}
	lis->array[lis->length + 1] = -1;
}

static void	lis_exec(t_ps *ps, t_lis *lis)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lis->size)
	{
		if (i == lis->array[j])
		{
			ft_exec(ps, RA);
			j++;
		}
		else
			ft_exec(ps, PB);
		i++;
	}
}

void	ft_lis(t_ps *ps)
{
	int		i;
	t_lis	lis;

	lis.stack = stack_to_array(ps->a);
	lis.size = stack_len(ps->a);
	lis.array = malloc(sizeof(int) * lis.size);
	lis.trace = malloc(sizeof(int) * lis.size);
	if (!lis.stack || !lis.array)
		ft_error(ps);
	i = 0;
	while (i < lis.size)
	{
		lis.array[i] = -1;
		lis.trace[i++] = -1;
	}
	lis.array[0] = 0;
	i = 1;
	lis.length = 0;
	while (i < lis.size)
		lis_loop(&lis, i++);
	lis_reverse(&lis);
	lis_exec(ps, &lis);
	free(lis.array);
	free(lis.trace);
	free(lis.stack);
}
