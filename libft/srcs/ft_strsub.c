/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:46:13 by marvin            #+#    #+#             */
/*   Updated: 2019/01/24 20:43:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;
	char	*point;

	i = 0;
	if (!s || len == 2147483647)
		return (NULL);
	result = (char*)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	point = result;
	while (i < start && start != 0)
	{
		s++;
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(point + i) = *(s + i);
		i++;
	}
	*(point + i) = '\0';
	return (result);
}
