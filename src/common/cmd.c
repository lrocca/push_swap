/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:36:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/15 19:30:20 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_cmdinit(t_cmd cmd[33])
{
	int	i;

	i = 0;
	while (i < 33)
		cmd[i++] = &ft_error;
	cmd[0] = &sa;
	cmd[3] = &sb;
	cmd[6] = &ss;
	cmd[9] = &pa;
	cmd[12] = &pb;
	cmd[15] = &ra;
	cmd[18] = &rb;
	cmd[21] = &rr;
	cmd[24] = &rra;
	cmd[28] = &rrb;
	cmd[32] = &rrr;
}
