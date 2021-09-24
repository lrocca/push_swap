/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:05:25 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/24 15:03:16 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_reverse(int *array, int *trace, int length)
{
	int	i;
	int	j;

	i = length;
	j = array[length];
	while (i >= 0)
	{
		array[i--] = j;
		j = trace[j];
	}
	array[length + 1] = -1;
}

static void	lis_loop(int *stack, int *array, int *trace, int size)
{
	int	i;
	int	j;
	int	length;

	i = 1;
	length = 0;
	while (i < size)
	{
		if (stack[i] > stack[array[length]] && length++)
		{
			array[length] = i;
			trace[array[length]] = array[length - 1];
		}
		else if (stack[i] < stack[array[0]])
			array[0] = i;
		else
		{
			j = 0;
			while (j < length + 1)
			{
				if (stack[i] < stack[array[j]])
				{
					array[j] = i;
					trace[array[j]] = array[j - 1];
					break ;
				}
				j++;
			}
		}
		i++;
	}
	lis_reverse(array, trace, length);
}

static void	lis_algo(t_ps *ps, int *stack, int *array, int size)
{
	int	*trace;
	int	i;

	trace = malloc(sizeof(int) * size);
	if (!trace)
		ft_error(ps);
	i = 0;
	while (i < size)
	{
		array[i] = -1;
		trace[i] = -1;
		i++;
	}
	array[0] = 0;
	lis_loop(stack, array, trace, size);
	free(trace);
}

static void	lis_exec(t_ps *ps, int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (i == array[j])
		{
			ft_exec(ps, RA);
			j++;
		}
		else
			ft_exec(ps, PB);
		i++;
	}
}

void	lis(t_ps *ps)
{
	int		*array;
	int		*stack;
	int		size;

	size = stack_len(ps->a);
	stack = stack_to_array(ps->a);
	array = malloc(sizeof(int) * size);
	if (!stack || !array)
		ft_error(ps);
	lis_algo(ps, stack, array, size);
	free(stack);
	lis_exec(ps, array, size);
	free(array);
}
