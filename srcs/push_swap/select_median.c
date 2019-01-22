/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:15:31 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 13:22:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_select_median(t_stack *stack, int n)
{
	int		*arr;
	int		i;
	int		o;
	int		tmp;

	i = 0;
	arr = (int*)malloc(sizeof(int) * n);
	while (i < n)
	{
		arr[i] = stack->elem[stack->top + i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		o = 0;
		while (o < n - 1 - i)
		{
			if (arr[o] > arr[o + 1])
			{
				tmp = arr[o];
				arr[o] = arr[o + 1];
				arr[o + 1] = tmp;
			}
			o++;
		}
		i++;
	}
	tmp = arr[n / 2];
	free(arr);
	return (tmp);
}
