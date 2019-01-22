/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:54:18 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 18:46:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sort_stack(t_stack *stack, int dir)
{
	size_t	i;

	i = 0;
	if (stack->size < 2)
		return (1);
	while (i < stack->size - 1)
	{
		if (dir > 0)
		{
			if ((i >= stack->top && stack->elem[i + 1] < stack->elem[i]))
				return (0);
		}
		else
		{
			if ((i >= stack->top && stack->elem[i + 1] > stack->elem[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
