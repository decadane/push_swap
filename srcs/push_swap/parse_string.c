/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:30:09 by marvin            #+#    #+#             */
/*   Updated: 2019/01/24 21:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_concat_strings(char *str, char *point, int n, char *res)
{
	char	*s;
	char	*m;
	char	*result;

	point++;
	result = ft_strnew(1);
	s = ft_strsub(str, 0, point - str);
	m = ft_strsub(str, point - str + n, ft_strlen(str) - (point - str) + n);
	result = ft_strjoin(result, s);
	result = ft_strjoin(result, res);
	result = ft_strjoin(result, m);
	return (result);
}

char		*ft_parse_string(char *res)
{
	char	*point;

//	printf("Old: %s|\n", res);
	while (1)
	{
		if ((point = ft_strstr(res, "\nrra\nra\n")) ||
				(point = ft_strstr(res, "\nrrb\nrb\n")) ||
				(point = ft_strstr(res, "\nra\nrra\n")) ||
				(point = ft_strstr(res, "\nrb\nrrb\n")))
			res = ft_concat_strings(res, point, 7, ft_strdup(""));
		else if ((point = ft_strstr(res, "\nsa\nsa\n")) ||
				(point = ft_strstr(res, "\nsb\nsb\n")) ||
				(point = ft_strstr(res, "\npa\npb\n"))
				|| (point = ft_strstr(res, "\npb\npa\n")))
			res = ft_concat_strings(res, point, 6, ft_strdup(""));
		else if ((point = ft_strstr(res, "\nra\nrb\n")) ||
				(point = ft_strstr(res, "\nrb\nra\n")))
			res = ft_concat_strings(res, point, 6, ft_strdup("rr\n"));
		else if ((point = ft_strstr(res, "\nrra\nrrb\n")) ||
				(point = ft_strstr(res, "\nrrb\nrra\n")))
			res = ft_concat_strings(res, point, 8, ft_strdup("rrr\n"));
		else if ((point = ft_strstr(res, "\nsa\nsb\n")) ||
				(point = ft_strstr(res, "\nsb\nsa\n")))
			res = ft_concat_strings(res, point, 6, ft_strdup("ss\n"));
		else
			break ;
//		getchar();
	}
	return (res);
}
