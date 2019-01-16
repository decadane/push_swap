/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:48:51 by marvin            #+#    #+#             */
/*   Updated: 2019/01/03 19:49:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_len(const char *s, int len)
{
	size_t	result;
	int		i;

	result = 0;
	i = 0;
	while (i < len)
	{
		while (*s)
		{
			result++;
			s++;
		}
		i++;
	}
	return (result);
}
