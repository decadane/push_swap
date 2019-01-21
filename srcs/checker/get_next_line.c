/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:08:23 by marvin            #+#    #+#             */
/*   Updated: 2018/12/05 17:06:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_tail_buffer	*ft_search_in_buffer(t_tail_buffer **s_buffer, int fd)
{
	t_tail_buffer	*head;

	head = *s_buffer;
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	head = (t_tail_buffer*)malloc(sizeof(t_tail_buffer));
	head->fd = fd;
	head->str = NULL;
	head->next = *s_buffer;
	head->end = 0;
	*s_buffer = head;
	return (*s_buffer);
}

static char		*ft_put_from_buffer(t_tail_buffer *current, int *flag)
{
	char	*result;
	char	*new_point;
	char	*b;

	new_point = ft_strchr(current->str, '\n');
	if (new_point)
	{
		b = ft_strdup(new_point + 1);
		result = ft_strsub(current->str, 0, new_point - current->str);
		if (ft_strlen(b) == 0)
		{
			free(b);
			b = NULL;
		}
		*flag = 0;
	}
	else
	{
		b = NULL;
		result = ft_strdup(current->str);
	}
	free(current->str);
	current->str = b;
	return (result);
}

static int		ft_pull_to_buffer(t_tail_buffer *current, int fd)
{
	int		len;
	char	string[BUFF_SIZE + 1];

	len = read(fd, string, BUFF_SIZE);
	if (len < BUFF_SIZE)
		current->end = 1;
	if (len == 0)
		return (0);
	string[len] = '\0';
	current->str = ft_strdup(string);
	return (1);
}

static void		ft_create_result(char **line, char *str_from_buffer)
{
	char	*str;
	size_t	len;

	len = ft_strlen(*line) + ft_strlen(str_from_buffer) + 1;
	str = ft_strnew(len);
	ft_strcat(str, *line);
	free(*line);
	ft_strcat(str, str_from_buffer);
	free(str_from_buffer);
	str[len - 1] = '\0';
	*line = str;
}

int				get_next_line(const int fd, char **line)
{
	static t_tail_buffer	*s_buffer;
	t_tail_buffer			*current;
	char					*str_from_buffer;
	int						flag;

	flag = 1;
	if (fd < 0 || !line || read(fd, &flag, 0) || !(*line = ft_strnew(0)))
		return (-1);
	current = ft_search_in_buffer(&s_buffer, fd);
	while (flag)
	{
		if (!(current->str) && !(ft_pull_to_buffer(current, fd)))
		{
			if (ft_strlen(*line) == 0)
				return (0);
			break ;
		}
		str_from_buffer = ft_put_from_buffer(current, &flag);
		ft_create_result(line, str_from_buffer);
	}
	return (1);
}
