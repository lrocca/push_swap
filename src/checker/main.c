/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:19:34 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/15 20:12:47 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, const char **av)
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	ps.flags = 0;
	ft_parse(&ps, av);
	if (ps.flags & FLAGS_V)
		ft_printstacks(&ps);
	ft_read(&ps);
	if (!ft_check(&ps))
		ft_putendl_fd(SUCCESS_MSG, STDOUT_FILENO);
	else
		ft_putendl_fd(FAILURE_MSG, STDOUT_FILENO);
	ft_exit(&ps, EXIT_SUCCESS);
	return (0);
}
