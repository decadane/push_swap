/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:54:11 by marvin            #+#    #+#             */
/*   Updated: 2019/01/16 21:14:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int		ft_swap(int *stack, int len)
{
	int		tmp;
	int		i;

	i = 0;
	if (len < 2)
		return (0);
	while (stack[i] == 0)
	{
		if (i == len - 2)
			return (0);
		i++;
	}
	tmp = stack[i];
	stack[i] = stack[i + 1];
	stack[i + 1] = tmp;
	return (1);
}

static int		ft_push(int *a_stack, int *b_stack, int len)
{
	int		i;
	int		tmp;

	i = 0;
	while (a_stack[i] == 0)
	{
		if (i == len - 1)
			return (0);
		i++;
	}
	tmp = a_stack[i];
	a_stack[i] = 0;
	i = 0;
	while (b_stack[i] == 0)
	{
		if (i == len)
			break ;
		i++;
	}
	b_stack[i - 1] = tmp;
	return (1);
}

static void		ft_rev_array(int *stack, int len)
{
	int		arr[len];
	int		i;

	i = 0;
	while (i < len)
	{
		arr[len - 1 - i] = stack[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		stack[i] = arr[i];
		i++;
	}
}

static int		ft_shift(int *stack, int len, int dir)
{
	int		i;
	int		tmp;

	i = 0;
	if (dir < 0)
		ft_rev_array(stack, len);
	while (stack[i] == 0)
	{
		if (i == len - 1)
			return (0);
		i++;
	}
	tmp = stack[i];
	while (stack[i] != 0 && i <= len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i - 1] = tmp;
	if (dir < 0)
		ft_rev_array(stack, len);
	return (1);
}

void			ft_call_function(int *a_stack, int *b_stack, char *c, int len)
{
	if (!ft_strcmp(c, "ss\n") || !ft_strcmp(c, "sa\n") || !ft_strcmp(c, "sb\n"))
	{
		if (!ft_strcmp(c, "sa\n") || !ft_strcmp(c, "ss\n"))
			ft_swap(a_stack, len);
		if (!ft_strcmp(c, "sb\n") || !ft_strcmp(c, "ss\n"))
			ft_swap(b_stack, len);
	}
	if (!ft_strcmp(c, "pa\n"))
		ft_push(b_stack, a_stack, len);
	if (!ft_strcmp(c, "pb\n"))
		ft_push(a_stack, b_stack, len);
	if (!ft_strcmp(c, "rr\n") || !ft_strcmp(c, "ra\n") || !ft_strcmp(c, "rb\n"))
	{
		if (!ft_strcmp(c, "ra\n") || !ft_strcmp(c, "rr\n"))
			ft_shift(a_stack, len, 1);
		if (!ft_strcmp(c, "rb\n") || !ft_strcmp(c, "rr\n"))
			ft_shift(b_stack, len, 1);
	}
	if (!ft_strcmp(c, "rrr\n") || !ft_strcmp(c, "rra\n") || !ft_strcmp(c, "rrb\n"))
	{
		if (!ft_strcmp(c, "rra\n") || !ft_strcmp(c, "rrr\n"))
			ft_shift(a_stack, len, -1);
		if (!ft_strcmp(c, "rrb\n") || !ft_strcmp(c, "rrr\n"))
			ft_shift(b_stack, len, -1);
	}
}
