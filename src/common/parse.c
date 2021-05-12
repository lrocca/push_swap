/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:35:11 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/12 16:47:04 by lrocca           ###   ########.fr       */
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

static void	handle_str(t_ps *ps, const char *s)
{
	int		i;
	char	**split;

	split = ft_splitspace(s);
	if (!split)
		ft_error(ps);
	i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i]))
			ft_error(ps);
		ft_nodeadd_back(&ps->a, ft_atoi(split[i++]));
	}
}

void	ft_parse(t_ps *ps)
{
	int	i;

	i = 1;
	ps->a = NULL;
	ps->b = NULL;
	while (ps->av[i])
		handle_str(ps, ps->av[i++]);
	return ;
}
