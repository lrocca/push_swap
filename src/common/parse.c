/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:35:11 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/25 19:05:06 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	is_valid_input(const char *s)
{
	int		i;
	char	sign;

	i = 0;
	sign = s[0] == '+' || s[0] == '-';
	while (s[i + sign])
		if (!ft_isdigit(s[i++ + sign]))
			return (0);
	return (i);
}

static char	is_unique(t_node *head, int n)
{
	t_node	*curr;

	if (!head)
		return (1);
	if (n == head->value)
		return (0);
	curr = head->next;
	while (curr != head)
	{
		if (n == curr->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	handle_str(t_ps *ps, const char *s)
{
	int		i;
	int		n;
	char	**split;

	split = ft_splitspace(s);
	if (!split)
		ft_error(ps);
	i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i]))
			ft_error(ps);
		n = ft_atoi(split[i++]);
		if (errno == -42)
			ft_error(ps);
		if (!is_unique(ps->a, n))
			ft_error(ps);
		ps->len++;
		ft_nodeadd_back(&ps->a, n);
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_parse(t_ps *ps, const char **av)
{
	int	i;

	i = 1;
	ps->len = 0;
	if (!ft_strcmp(av[i], "-v"))
	{
		ps->flags |= FLAGS_V;
		i++;
	}
	ps->a = NULL;
	ps->b = NULL;
	while (av[i])
		handle_str(ps, av[i++]);
	return ;
}
