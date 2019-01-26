/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:30:09 by marvin            #+#    #+#             */
/*   Updated: 2019/01/26 18:33:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_replace_substring(char *str, char *old_str, char *new_str)
{
	char	*point;
	char	*end_paste;
	char	*res;

	if (!(point = ft_strstr(str, old_str)))
		return (str);
	res = ft_strnew(1);
	res = ft_strjoin(res, ft_strsub(str, 0, point - str));
	res = ft_strjoin(res, ft_strdup(new_str));
	if (point - str + ft_strlen(old_str) <= ft_strlen(str))
	{
		end_paste = point + ft_strlen(old_str);
		res = ft_strjoin(res, ft_strsub(str, end_paste - str,
					ft_strlen(str) - (end_paste - str)));
	}
	free(str);
	return (res);
}

char		*ft_parse_string(char *res)
{
	size_t	old_len;

	old_len = 0;
	while (old_len != ft_strlen(res))
	{
		old_len = ft_strlen(res);
		res = ft_replace_substring(res, "\nrra\nra\n", "\n");
		res = ft_replace_substring(res, "\nrrb\nrb\n", "\n");
		res = ft_replace_substring(res, "\nra\nrra\n", "\n");
		res = ft_replace_substring(res, "\nrb\nrrb\n", "\n");
		res = ft_replace_substring(res, "\nsa\nsa\n", "\n");
		res = ft_replace_substring(res, "\nsb\nsb\n", "\n");
		res = ft_replace_substring(res, "\npa\npb\n", "\n");
		res = ft_replace_substring(res, "\npb\npa\n", "\n");
		res = ft_replace_substring(res, "\nra\nrb\n", "\nrr\n");
		res = ft_replace_substring(res, "\nrb\nra\n", "\nrr\n");
		res = ft_replace_substring(res, "\nrrb\nrra\n", "\nrrr\n");
		res = ft_replace_substring(res, "\nrra\nrrb\n", "\nrrr\n");
		res = ft_replace_substring(res, "\nsa\nsb\n", "\nss\n");
		res = ft_replace_substring(res, "\nsb\nsa\n", "\nss\n");
	}
	return (res);
}
