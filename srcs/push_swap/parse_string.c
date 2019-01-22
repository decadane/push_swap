/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:30:09 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 21:50:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_concat_strings(char *str, char *point, int n, char *res)
{
	char	*s;
	char	*m;
	char	*result;

	result = ft_strnew(0);
	s = ft_strsub(str, point - str, n);
	m = ft_strsub(str, point - str + n, ft_strlen(str) - (point - str) + n);
	result = ft_strjoin(result, s);
	result = ft_strjoin(result, res);
	result = ft_strjoin(result, m);
	free(str);
	return (result);
}

char		*ft_parse_string(char *res)
{
	char	*point;

	while (1)
	{
		if ((point = ft_strstr(res, "sa\nsa\n")) ||
				(point = ft_strstr(res, "sb\nsb\n")) ||
				(point = ft_strstr(res, "pa\npb\n"))
				|| (point = ft_strstr(res, "pb\npa\n")))
			res = ft_concat_strings(res, point, 6, ft_strdup(""));
		else if ((point = ft_strstr(res, "ra\nrra\n")) ||
				(point = ft_strstr(res, "rb\nrrb\n")) ||
				(point = ft_strstr(res, "rra\nra\n")) ||
				(point = ft_strstr(res, "rrb\nrb\n")))
			res = ft_concat_strings(res, point, 7, ft_strdup(""));
		else if ((point = ft_strstr(res, "sa\nsb\n")) ||
				(point = ft_strstr(res, "sb\nsa\n")))
			res = ft_concat_strings(res, point, 6, ft_strdup("ss"));
		else if ((point = ft_strstr(res, "ra\nrb\n")) ||
				(point = ft_strstr(res, "rb\nra\n")))
			res = ft_concat_strings(res, point, 6, ft_strdup("rr"));
		else if ((point = ft_strstr(res, "rra\nrrb\n")) ||
				(point = ft_strstr(res, "rrb\nrra\n")))
			res = ft_concat_strings(res, point, 8, ft_strdup("rrr"));
		else
			break ;
	}
	return (res);
}
