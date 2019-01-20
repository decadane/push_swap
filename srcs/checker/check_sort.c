/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:29:18 by marvin            #+#    #+#             */
/*   Updated: 2019/01/20 14:42:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_sort(t_stack *a_stack, t_stack *b_stack)
{
	size_t	i;

	i = 0;
	if (a_stack->size < 2)
	{
		ft_putstr("[OK]\n");
		return ;
	}
	while (i < a_stack->size - 1)
	{
		if ((i >= a_stack->top && a_stack->elem[i + 1] < a_stack->elem[i])
				|| b_stack->top != b_stack->size)
		{
			ft_putstr("[KO]\n");
			return ;
		}
		i++;
	}
	ft_putstr("[OK]\n");
}
