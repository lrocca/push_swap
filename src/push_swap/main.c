/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:53:44 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/18 21:38:03 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, const char **av)
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	ps.flags = 0;
	ps.flags |= FLAGS_PS;
	ft_parse(&ps, av);
	if (ft_issorted(ps.a))
		ft_exit(&ps, EXIT_SUCCESS);
	if (ps.len < 6)
		ft_sort_five(&ps);
	else
		ft_putendl_fd("more than 5", STDOUT_FILENO);
	// ft_printstacks(&ps);
	if (ft_check(&ps))
		ft_error(&ps);
	ft_exit(&ps, EXIT_SUCCESS);
	return (0);
}
