/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:23:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/24 17:15:33 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "main.h"

# define	SA	"sa"
# define	SB	"sb"
# define	SS	"ss"
# define	PA	"pa"
# define	PB	"pb"
# define	RA	"ra"
# define	RB	"rb"
# define	RR	"rr"
# define	RRA	"rra"
# define	RRB	"rrb"
# define	RRR	"rrr"

typedef struct s_lis
{
	int	*array;
	int	*trace;
	int	*stack;
	int	size;
	int	length;
}	t_lis;

void	ft_sort_three(t_ps *ps);
void	ft_sort_five(t_ps *ps);
void	ft_sort_n(t_ps *ps);

void	ft_lis(t_ps *ps);
int		calc_best(t_ps *ps);

int		stack_len(t_node *head);
int		*stack_to_array(t_node *head);

#endif
