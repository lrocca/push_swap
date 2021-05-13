/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:27:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/13 03:57:56 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	new_op(t_ps *ps, char c)
{
	static char	buffer[4] = {0};
	int	i;

	i = 0;
	if (c != '\n')
	{
		while (buffer[i] && i < 4)
			i++;
		if (i > 2 || !ft_isalpha(c))
			ft_error(ps);
		buffer[i] = c;
		if (ft_strnstr(OPS, buffer, OPS_LEN) != (char *)&OPS)
			ft_lstadd_back(&ps->op, ft_lstnew(ft_strdup(buffer)));
		else if (!buffer[2])
			;
		else
			ft_error(ps);
	}
	else if (ft_strlen(buffer))
		ft_error(ps);
	ft_bzero(buffer, 4);
	return (ft_strlen(buffer));
}

void	ft_read(t_ps *ps)
{
	int		ret;
	char	c;
	char	count;

	ret = 1;
	while (ret)
	{
		ret = read(STDIN_FILENO, &c, 1);
		count = new_op(ps, c);
	}
	if (count)
		ft_error(ps);
}
