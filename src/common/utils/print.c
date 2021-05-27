/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:04:26 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/27 20:07:18 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_putchartimes(char c, size_t times)
{
	while (times--)
		ft_putchar_fd(c, STDOUT_FILENO);
}

int	abs_numlen(int n)
{
	char	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (ft_numlen(n * sign, BASE) + (n < 0));
}

int	stack_max(t_node *head)
{
	t_node	*curr;
	int		max;
	int		len;

	if (!head)
		return (0);
	max = abs_numlen(head->value);
	curr = head->next;
	while (curr != head)
	{
		len = abs_numlen(curr->value);
		if (len > max)
			max = len;
		curr = curr->next;
	}
	return (max);
}
