/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:51:28 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/24 14:52:34 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_node *head)
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
