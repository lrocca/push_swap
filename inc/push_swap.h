/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:23:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/09/22 19:46:36 by lrocca           ###   ########.fr       */
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

void	set_indices(t_ps *ps);

void	ft_sort_three(t_ps *ps);
void	ft_sort_five(t_ps *ps);
void	ft_sort_n(t_ps *ps);

void	lis(t_ps *ps);

#endif
