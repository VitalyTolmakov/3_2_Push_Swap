/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:06:30 by fheidi            #+#    #+#             */
/*   Updated: 2021/12/11 14:34:59 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_with_new_str(char **line, int nbr_read, char **bf)
{
	char	*new_line;

	free(*bf);
	if (nbr_read)
	{
		new_line = ft_strjoin(*line, "\n");
		if (new_line == NULL)
			return (NULL);
		free(*line);
		return (new_line);
	}
	else if (*line[0] == '\0')
	{
		free(*line);
		return (NULL);
	}
	else
		return (*line);
}

char	*get_remains(char **remains, char **line)
{
	char	*p_n;
	char	*p_free;

	p_n = NULL;
	if (*remains != NULL)
	{
		p_n = ft_strchr(*remains, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(*remains);
			p_free = *remains;
			*remains = ft_strdup(++p_n);
		}
		else
		{
			*line = ft_strdup(*remains);
			p_free = *remains;
			*remains = ft_calloc(ft_strlen(*remains), 1);
		}
		free(p_free);
	}
	else
		*line = ft_calloc(1, sizeof(char));
	return (p_n);
}

int	get_nbr_read(int *nbr_read, int fd, char **buf)
{
	*nbr_read = read(fd, *buf, BUFFER_SIZE);
	return (*nbr_read);
}

int	init_bf_ln(char **buf, char **line)
{
	*line = NULL;
	*buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (*buf == NULL)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	t_help		h;

	if (fd < 0 || read(fd, NULL, 0) == -1 || fd > MAX || BUFFER_SIZE < 1
		|| !init_bf_ln(&h.buf, &h.line))
		return (NULL);
	h.p_n = get_remains(&remains, &h.line);
	while (!h.p_n && get_nbr_read(&h.nbr_read, fd, &h.buf))
	{
		h.buf[h.nbr_read] = '\0';
		h.p_n = ft_strchr(h.buf, '\n');
		if (h.p_n)
		{
			*h.p_n = '\0';
			free(remains);
			remains = ft_strdup(++h.p_n);
		}
		h.p_free = h.line;
		h.line = ft_strjoin(h.line, h.buf);
		free(h.p_free);
	}
	return (get_line_with_new_str(&h.line, h.nbr_read, &h.buf));
}
