/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:54:57 by marvin            #+#    #+#             */
/*   Updated: 2019/01/16 20:00:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int		ft_check_doubles(int *stack, int num, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (stack[i] == num)
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
