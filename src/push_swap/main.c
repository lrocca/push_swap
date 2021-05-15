/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:53:44 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/15 20:29:44 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, const char **av)
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	ps.flags = 0;
	ft_parse(&ps, av);
	if (ft_issorted(ps.a))
		ft_exit(&ps, EXIT_SUCCESS);
	ft_printstacks(&ps);
	ft_exit(&ps, EXIT_SUCCESS);
	return (0);
}
