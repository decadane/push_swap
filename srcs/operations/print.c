/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:41:17 by marvin            #+#    #+#             */
/*   Updated: 2019/01/27 17:41:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_print_stack(t_stack *a_stack, t_stack *b_stack)
{
	size_t	i;

	i = 0;
	ft_putchar('\n');
	while (i < a_stack->size)
	{
		if (i >= a_stack->top)
			ft_putnbr(a_stack->elem[i]);
		else
			ft_putchar('.');
		ft_putstr("\t");
		if (i >= b_stack->top)
			ft_putnbr(b_stack->elem[i]);
		else
			ft_putchar('.');
		ft_putstr("\n");
		i++;
	}
	ft_putstr("-\t-\n");
	ft_putstr("a\tb\n");
}
