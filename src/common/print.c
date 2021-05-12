/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:45:12 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/12 16:43:42 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static size_t	ft_max(size_t a, size_t b)
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

static int	stack_max(t_node *head)
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
	if (ps->a)
		curr_a = ps->a->next;
	if (ps->b)
		curr_b = ps->b->next;
	while ((ps->a && curr_a != ps->a) || (ps->b && curr_b != ps->b))
	{
		if (curr_a == ps->a)
			print_row(NULL, curr_b, max);
		if (curr_b == ps->b)
			print_row(curr_a, NULL, max);
		if (curr_a != ps->a && curr_b != ps->b)
			print_row(ps->a, ps->b, max);
		if (curr_a)
			curr_a = curr_a->next;
		if (curr_b)
			curr_b = curr_b->next;
	}
	print_footer(max);
}
