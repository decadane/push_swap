/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:41:44 by marvin            #+#    #+#             */
/*   Updated: 2018/12/22 21:45:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_power(int num, int power)
{
	int					i;
	unsigned long long	res;

	i = 0;
	res = 1;
	while (i < power)
	{
		res *= num;
		i++;
	}
	return (res);
}
