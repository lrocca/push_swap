/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:03:56 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/15 19:50:24 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	ft_issorted(t_node *head)
{
	t_node	*curr;
	int		value;

	value = head->value;
	curr = head->next;
	while (curr != head)
	{
		if (value > curr->value)
			return (0);
		value = curr->value;
		curr = curr->next;
	}
	return (1);
}

char	ft_check(t_ps *ps)
{
	if (ps->b || !ps->a)
		return (1);
	return (!ft_issorted(ps->a));
}
