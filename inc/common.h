/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:05:12 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/27 20:06:50 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "main.h"

/*
** Base used to convert from input
*/
# define	BASE	10

/*
** Print options
*/
# define	PRINT_DIV_VER	'|'
# define	PRINT_DIV_HOR	'-'
# define	PRINT_SPACE		' '
# define	PRINT_NAME_A	'a'
# define	PRINT_NAME_B	'b'

size_t	ft_max(size_t a, size_t b);
void	ft_putchartimes(char c, size_t times);
int		abs_numlen(int n);
int		stack_max(t_node *head);

#endif
