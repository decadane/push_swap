/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:50:28 by marvin            #+#    #+#             */
/*   Updated: 2019/01/21 18:41:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"
# include <sys/stat.h>
# include <fcntl.h>

typedef struct				s_tail_buffer
{
	int						fd;
	char					*str;
	struct s_tail_buffer	*next;
	int						end;
}							t_tail_buffer;

int							get_next_line(const int fd, char **line);

#endif
