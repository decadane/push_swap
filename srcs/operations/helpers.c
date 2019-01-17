/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:54:57 by marvin            #+#    #+#             */
/*   Updated: 2019/01/17 18:49:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int		ft_check_doubles(t_e *stack, int num, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (stack[i].elem == num && stack[i].edit == 1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_mini_atoi(char *str)
{
	long	res;
	int		len;
	int		neg;
	int		i;

	res = 0;
	i = -1;
	neg = 0;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	len = ft_strlen(str);
	while (++i < len)
		res = str[i] - '0' + res * 10;
	if (neg)
	{
		res *= -1;
		neg = 0;
	}
	if ((res - (int)res))
		return (0);
	return (res);
}

void	ft_stack_init(t_e *a_stack, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		a_stack[i].elem = 0;
		a_stack[i].edit = 0;
		i++;
	}
}

void	ft_print_stack(t_e *a_stack, t_e *b_stack, int len)
{
	int		i;

	i = 0;
	ft_putchar('\n');
	while (i < len)
	{
		ft_putstr("   ");
		if (a_stack[i].edit != 0)
			ft_putnbr(a_stack[i].elem);
		else
			ft_putchar('.');
		ft_putstr("\t  ");
		if (b_stack[i].edit != 0)
			ft_putnbr(b_stack[i].elem);
		else
			ft_putchar('.');
		ft_putstr("\n\n");
		i++;
	}
	ft_putstr("Stack A\tStack B\n");
}
