/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:29:18 by marvin            #+#    #+#             */
/*   Updated: 2019/01/17 18:51:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_sort(t_e *a_stack, t_e *b_stack, int len)
{
	int		i;

	i = 0;
	if (len < 2)
		ft_putstr("[OK]\n");
	while (i < len - 1)
	{
		if ((a_stack[i + 1].elem < a_stack[i].elem && a_stack[i + 1].edit == 1
				&& a_stack[i].edit == 1) || b_stack[i + 1].edit != 0)
		{
			ft_putstr("[KO]\n");
			return ;
		}
		i++;
	}
	ft_putstr("[OK]\n");
}
