/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:08:43 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/17 20:33:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_exec(t_ps *ps, const char *s)
{
	static t_cmd	cmd[33] = {NULL};
	char			*ops;
	char			*ret;

	ops = OPS;
	if (cmd[0] == NULL)
		ft_cmdinit(cmd);
	ret = ft_strnstr(ops, s, OPS_LEN);
	if (!ret)
		ft_error(ps);
	cmd[ret - ops - 1](ps);
	if (ps->flags & FLAGS_PS)
		ft_putendl_fd((char *)s, STDOUT_FILENO);
	if (ps->flags & FLAGS_V)
		ft_printstacks(ps);
}
