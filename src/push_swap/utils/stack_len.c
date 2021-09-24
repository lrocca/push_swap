/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:51:01 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/24 14:51:15 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *head)
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
