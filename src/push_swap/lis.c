/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:05:25 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/22 20:00:47 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	stack_len(t_node *head)
{
	t_node	*curr;
	int		len;

	if (!head)
		return (0);
	len = 1;
	curr = head->next;
	while (curr != head)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

static int	*stack_to_array(t_node *head)
{
	int		*array;
	t_node	*curr;
	int		i;

	array = malloc(sizeof(int) * stack_len(head));
	if (!array)
		return (NULL);
	i = 0;
	array[i++] = head->value;
	curr = head->next;
	while (curr != head)
	{
		array[i++] = curr->value;
		curr = curr->next;
	}
	return (array);
}

void	lis(t_ps *ps)
{
	int		*array;
	int		*trace;
	int		*stack;
	int		i;
	int		j;
	int		size;
	int		length;

	stack = stack_to_array(ps->a);
	size = stack_len(ps->a);
	array = malloc(sizeof(int) * size);
	trace = malloc(sizeof(int) * size);
	if (!stack || !array)
		ft_error(ps);
	j = 0;
	while (j < size)
	{
		array[j] = -1;
		trace[j++] = -1;
	}
	array[0] = 0;
	i = 1;
	length = 0;
	while (i < size)
	{
		if (stack[i] > stack[array[length]])
		{
			length++;
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
	j = array[length];
	i = length;
	while (i >= 0)
	{
		array[i--] = j;
		j = trace[j];
	}
	array[length + 1] = -1;

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

	free(array);
	free(trace);
	free(stack);
}
