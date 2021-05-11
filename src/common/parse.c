/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:35:11 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/11 19:55:35 by lrocca           ###   ########.fr       */
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

static void	handle_str(const char *s, t_node **head)
{
	int		i;
	char	**split;

	split = ft_splitspace(s);
	if (!split)
		ft_error();
	i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i]))
			ft_error();
		ft_nodeadd_back(head, ft_atoi(split[i++]));
	}
}

t_node	*ft_parse(const char **av)
{
	int		i;
	t_node	*head;

	i = 1;
	head = NULL;
	while (av[i])
		handle_str(av[i++], &head);
	return (head);
}
