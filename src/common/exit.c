/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:31:43 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/13 03:19:42 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_exit(t_ps *ps, int n)
{
	ft_free(ps);
	exit(n);
}

void	ft_error(t_ps *ps)
{
	ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
	ft_exit(ps, EXIT_FAILURE);
}
