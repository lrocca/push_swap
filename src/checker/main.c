/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:19:34 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/13 03:31:45 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, const char **av)
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	ps.av = av;
	ft_parse(&ps);
	ft_read(&ps);
	// execute operations
	if (ft_check(&ps))
		ft_putendl_fd(SUCCESS_MSG, STDOUT_FILENO);
	else
		ft_putendl_fd(FAILURE_MSG, STDOUT_FILENO);
	ft_exit(&ps, EXIT_SUCCESS);
	return (0);
}
