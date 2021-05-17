/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:27:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/05/17 20:33:58 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_bufjoin(char *line, char buffer[128])
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!new)
		return (NULL);
	while (line && line[j])
		new[i++] = line[j++];
	if (line)
	{
		free(line);
		line = NULL;
	}
	j = 0;
	while (buffer && buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	return (new);
}

static char	get_next_line(int fd, char **line)
{
	int		n;
	int		i;
	char	c;
	char	buffer[128];

	*line = NULL;
	i = 0;
	n = 1;
	while (n > 0)
	{
		n = read(fd, &c, 1);
		if (c == '\n')
			break ;
		buffer[i] = c;
		i++;
		if (i == 127)
		{
			buffer[i] = '\0';
			*line = ft_bufjoin(*line, buffer);
			i = 0;
		}
	}
	buffer[i] = '\0';
	*line = ft_bufjoin(*line, buffer);
	return (n);
}

static void	check_op(t_ps *ps, char **line, char gnl)
{
	if (!*line || (gnl && ft_strlen(*line) == 0) || ft_strchr(*line, ' '))
		ft_error(ps);
	if (ft_strlen(*line))
		ft_exec(ps, *line);
}

void	ft_read(t_ps *ps)
{
	char	ret;
	char	*line;

	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		check_op(ps, &line, ret);
	}
	if (ret < 0)
		ft_error(ps);
}
