/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:27:54 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/11 20:43:42 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>

# include "libft.h"

/*
** @todo atoi_base
*/
# define	BASE	10

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}	t_node;

/*
** common
*/

/*
** main.c
*/

/*
** Create a new node.
**
** @param	prev	The pointer to the previous node
** @param	next	The pointer to the next node
** @param	value	The value of the new node
**
** @return	The new node
*/
t_node	*ft_nodenew(t_node *prev, t_node *next, int value);

/*
** Add a new node to the end of the circular linked list.
**
** @param	value	The value of the new node
** @param	head	The pointer to the first node
*/
void	ft_nodeadd_back(t_node **head, int value);

/*
** parse.c
*/

/*
** Parse the argument values and add each number as a node to a circular linked
** list.
**
** @param	av	The arguments values array.
**
** @return	The pointer to the first node
*/
t_node	*ft_parse(const char **av);

/*
** exit.c
*/

/*
** Exit the program cleanly.
**
** @param	n	The exit code
*/
void	ft_exit(int n);

/*
** Print `Error\\n` on the standard error, then call `ft_exit`.
**
** @return
*/
void	ft_error(void);

/*
** print.c
*/

/*
** @param	a	The first stack
** @param	b	The second stack
*/
void	ft_printstacks(t_node *a, t_node *b);

#endif
