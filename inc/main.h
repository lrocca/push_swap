/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:27:54 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/13 03:12:11 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

# define SUCCESS_STR	"OK"
# define FAILURE_STR	"KO"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}	t_node;

typedef struct s_ps
{
	const char	**av;
	t_node		*a;
	t_node		*b;
}	t_ps;

/*
** COMMON
*/

/*
** main.c
*/

/*
** Create a new node.
**
** @param	value	The value of the new node
** @param	prev	The pointer to the previous node
** @param	next	The pointer to the next node
**
** @return	The new node
*/
t_node	*ft_nodenew(int value, t_node *prev, t_node *next);

/*
** Add a new node to the end of the circular linked list.
**
** @param	head	The pointer to the first node
** @param	value	The value of the new node
*/
void	ft_nodeadd_back(t_node **head, int value);

/*
** Push a node to the front of a circular linked list.
**
** @param	head	The pointer to the first node
** @param	new		The pointer to the node to push
*/
void	ft_nodepush_front(t_node **head, t_node *new);

/*
** parse.c
*/

/*
** Parse the argument values and add each number as a node to a circular linked
** list.
**
** @param	ps	The pointer of the program's structure
*/
void	ft_parse(t_ps *ps);

/*
** check.c
*/

/*
** Check if the given circular linked list is sorted in ascending order.
**
** @param	head	The pointer to the first node
** @return	`1` if sorted, `0` if not
*/
char	ft_issorted(t_node *head);

/*
** Check if stack A is sorted and stack B is empty.
**
** @param	ps	The pointer of the program's structure
** @return	Non-zero if something is off
*/
char	ft_check(t_ps *ps);

/*
** exit.c
*/

/*
** Exit the program cleanly.
** Call `ft_free` function defined by the program with `strct` as parameter.
**
** @param	ps	The pointer of the program's structure
** @param	n	The exit code
*/
void	ft_exit(t_ps *ps, int n);

/*
** Print `Error\\n` on the standard error, then call `ft_exit`.
**
** @return	ps	The pointer of the program's structure
*/
void	ft_error(t_ps *ps);

/*
** print.c
*/

/*
** Print the two stacks.
**
** @param	ps	The pointer of the program's structure
*/
void	ft_printstacks(t_ps *ps);

/*
** Operations
*/

/*
** Swap the first 2 elements at the top of stack A.
** Do nothing if there is only one or no elements.
**
** @param	ps	The pointer of the program's structure
*/
void	sa(t_ps *ps);

/*
** Swap the first 2 elements at the top of stack B.
** Do nothing if there is only one or no elements.
**
** @param	ps	The pointer of the program's structure
*/
void	sb(t_ps *ps);

/*
** `sa` and `sb` at the same time.
**
** @param	ps	The pointer of the program's structure
*/
void	ss(t_ps *ps);

/*
** Take the first element at the top of B and put it at the top of A.
** Do nothing if B is empty.
**
** @param	ps	The pointer of the program's structure
*/
void	pa(t_ps *ps);

/*
** Take the first element at the top of A and put it at the top of B.
** Do nothing if A is empty.
**
** @param	ps	The pointer of the program's structure
*/
void	pb(t_ps *ps);

/*
** Shift up all elements of stack A by 1.
** The first element becomes the last one.
**
** @param	ps	The pointer of the program's structure
*/
void	ra(t_ps *ps);

/*
** Shift up all elements of stack B by 1.
** The first element becomes the last one.
**
** @param	ps	The pointer of the program's structure
*/
void	rb(t_ps *ps);

/*
** `ra` and `rb` at the same time.
**
** @param	ps	The pointer of the program's structure
*/
void	rr(t_ps *ps);

/*
** Shift down all elements of stack A by 1.
** The last elementbecomes the first one.
**
** @param	ps	The pointer of the program's structure
*/
void	rra(t_ps *ps);

/*
** Shift down all elements of stack B by 1.
** The last element becomes the first one.
**
** @param	ps	The pointer of the program's structure
*/
void	rrb(t_ps *ps);

/*
** `rra` and `rrb` at the same time.
**
** @param	ps	The pointer of the program's structure
*/
void	rrr(t_ps *ps);

/*
** DEFINED BY THE PROGRAM
*/

/*
** Free the allocated variables of the structure of the program.
**
** @param	ps	The pointer of the program's structure
*/
void	ft_free(t_ps *ps);

#endif
