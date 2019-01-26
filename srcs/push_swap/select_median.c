/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:15:31 by marvin            #+#    #+#             */
/*   Updated: 2019/01/26 14:56:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_select_median(t_stack *stack, int n)
{
	int		*arr;
	int		i[2];
	int		tmp;

	i[0] = -1;
	arr = (int*)malloc(sizeof(int) * n);
	while (++i[0] < n)
		arr[i[0]] = stack->elem[stack->top + i[0]];
	i[0] = -1;
	while (++i[0] < n)
	{
		i[1] = -1;
		while (++i[1] < n - 1 - i[0])
		{
			if (arr[i[1]] > arr[i[1] + 1])
			{
				tmp = arr[i[1]];
				arr[i[1]] = arr[i[1] + 1];
				arr[i[1] + 1] = tmp;
			}
		}
	}
	tmp = arr[n / 2];
	free(arr);
	return (tmp);
}
