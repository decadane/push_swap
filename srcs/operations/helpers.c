/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:54:57 by marvin            #+#    #+#             */
/*   Updated: 2019/01/24 20:01:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int		ft_check_doubles(t_stack *stack, int num, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (stack->elem[i] == num)
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

t_stack	*ft_stack_init(size_t len)
{
	t_stack	*stack;
	size_t	i;

	i = 0;
	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->top = len;
	stack->size = len;
	stack->elem = (int*)malloc(sizeof(int) * len);
	while (i < len)
	{
		stack->elem[i] = 0;
		i++;
	}
	return (stack);
}

t_stack	*ft_copy_stack(t_stack *stack)
{
	t_stack	*new_stack;
	size_t	i;

	i = 0;
	new_stack = (t_stack*)malloc(sizeof(t_stack));
	new_stack->top = stack->top;
	new_stack->size = stack->size;
	new_stack->elem = (int*)malloc(sizeof(int) * stack->size);
	while (i < stack->size)
	{
		new_stack->elem[i] = stack->elem[i];
		i++;
	}
	return (new_stack);
}

void	ft_delete_stacks(t_stack *a_stack, t_stack *b_stack)
{
	free(a_stack->elem);
	free(a_stack);
	a_stack = NULL;
	free(b_stack->elem);
	free(b_stack);
	b_stack = NULL;
}

void	ft_print_stack(t_stack *a_stack, t_stack *b_stack)
{
	size_t	i;

	i = 0;
	ft_putchar('\n');
	while (i < a_stack->size)
	{
		ft_putstr("   ");
		if (i >= a_stack->top)
			ft_putnbr(a_stack->elem[i]);
		else
			ft_putchar('.');
		ft_putstr("\t  ");
		if (i >= b_stack->top)
			ft_putnbr(b_stack->elem[i]);
		else
			ft_putchar('.');
		ft_putstr("\n\n");
		i++;
	}
	ft_putstr("Stack A\tStack B\n");
}

void	ft_print(t_stack *a_stack)
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
		ft_putchar('\n');
		i++;
	}
	ft_putstr("Stack A\n");
}
