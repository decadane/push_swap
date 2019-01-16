/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:54:57 by marvin            #+#    #+#             */
/*   Updated: 2019/01/16 18:06:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_stack_init(int *a_stack, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		a_stack[i] = 0;
		i++;
	}
}

void	ft_print_stack(int *a_stack, int *b_stack, int len)
{
	int		i;

	i = 0;
	ft_putchar('\n');
	while (i < len)
	{
		ft_putstr("   ");
		ft_putnbr(a_stack[i]);
		ft_putstr("\t\t  ");
		ft_putnbr(b_stack[i]);
		ft_putstr("\n\n");
		i++;
	}
	ft_putstr("Stack A\t\tStack B\n");
}
