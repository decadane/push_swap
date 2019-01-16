/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:44:21 by marvin            #+#    #+#             */
/*   Updated: 2019/01/03 19:46:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_len(char const *s, int len)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (i < len)
	{
		ft_putchar(s[i]);
		i++;
	}
}
