/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_array1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:24:49 by marvin            #+#    #+#             */
/*   Updated: 2018/12/09 17:27:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_array1(int len, int arr[len], int value)
{
	int		i;

	i = 0;
	while (i < len)
	{
		arr[i] = value;
		i++;
	}
}