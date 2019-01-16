/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:59:03 by marvin            #+#    #+#             */
/*   Updated: 2018/12/20 21:39:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char **str)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	len = ft_strlen(*str);
	result = (char*)malloc(len + 1);
	while (i < len)
	{
		result[i] = (*str)[len - i - 1];
		i++;
	}
	result[len] = '\0';
	*str = result;
}
