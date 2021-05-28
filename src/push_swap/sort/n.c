/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:27:10 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/28 18:32:30 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	stack_len(t_node *head)
// {
// 	t_node	*curr;
// 	int		len;

// 	len = 0;
// 	if (head)
// 	{
// 		len++;
// 		curr = head->next;
// 		while (curr != head)
// 		{
// 			len++;
// 			curr = curr->next;
// 		}
// 	}
// 	return (len);
// }

static void	move_if(t_ps *ps, int i, char stack)
{
	if (stack == 'a')
	{
		if (((ps->a->index >> i) & 1) == 1)
			ft_exec(ps, RA);
		else
			ft_exec(ps, PB);
		return ;
	}
	if (((ps->b->index >> i) & 1) == 1)
		ft_exec(ps, RB);
	else
		ft_exec(ps, PA);
}

static void	stack_reset(t_ps *ps)
{
	int	len;

	len = ps->len;
	// if (stack_len(ps->a) > len / 2)
		while (ps->b)
			ft_exec(ps, PA);
	// else
	// 	while (ps->a)
	// 		ft_exec(ps, PB);
}

static void	loop(t_ps *ps, int i)
{
	int		len;
	char	stack;

	stack = 'a';
	if (ps->b)
		stack = 'b';
	len = ps->len;
	while (len--)
		move_if(ps, i, stack);
	stack_reset(ps);
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
		// if (ft_issorted(ps->b))
		// {
		// 	while (ps->b)
		// 	{
		// 		/* code */
		// 	}
		// }
		i++;
	}
}
