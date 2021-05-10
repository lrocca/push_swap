/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:27:54 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/10 20:06:05 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "common.h"

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}	t_node;

#endif
