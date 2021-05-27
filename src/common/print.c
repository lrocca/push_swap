/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:45:12 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/27 20:06:10 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	print_num(int n, int max)
{
	int	padding;

	padding = max - abs_numlen(n);
	while (padding--)
		ft_putchar_fd(PRINT_SPACE, STDOUT_FILENO);
	ft_putnbr_fd(n, STDOUT_FILENO);
}

static void	print_row(t_node *a, t_node *b, int max)
{
	char	div[4];

	div[0] = PRINT_SPACE;
	div[1] = PRINT_DIV_VER;
	div[2] = PRINT_SPACE;
	div[3] = '\0';
	ft_putchar_fd(PRINT_SPACE, STDOUT_FILENO);
	if (a)
		print_num(a->value, max);
	else
		ft_putchartimes(PRINT_SPACE, max);
	ft_putstr_fd(div, STDOUT_FILENO);
	if (b)
		print_num(b->value, max);
	else
		ft_putchartimes(PRINT_SPACE, max);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	print_footer(int max)
{
	ft_putchartimes(PRINT_DIV_HOR, (max + 2) * 2 + 1);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putchartimes(PRINT_SPACE, max);
	ft_putchar_fd(PRINT_NAME_A, STDOUT_FILENO);
	ft_putchartimes(PRINT_SPACE, max + 2);
	ft_putchar_fd(PRINT_NAME_B, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ft_printstacks(t_ps *ps)
{
	t_node	*curr_a;
	t_node	*curr_b;
	int		max;

	max = ft_max(stack_max(ps->a), stack_max(ps->b));
	print_row(ps->a, ps->b, max);
	curr_a = NULL;
	curr_b = NULL;
	if (ps->a && ps->a != ps->a->next)
		curr_a = ps->a->next;
	if (ps->b && ps->b != ps->b->next)
		curr_b = ps->b->next;
	while (curr_a || curr_b)
	{
		print_row(curr_a, curr_b, max);
		if (curr_a)
			curr_a = curr_a->next;
		if (curr_b)
			curr_b = curr_b->next;
		if (curr_a == ps->a)
			curr_a = NULL;
		if (curr_b == ps->b)
			curr_b = NULL;
	}
	print_footer(max);
}
