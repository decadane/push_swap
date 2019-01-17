/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:54:11 by marvin            #+#    #+#             */
/*   Updated: 2019/01/17 19:12:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int		ft_swap(t_e *stack, int len)
{
	int		tmp;
	int		i;

	i = 0;
	if (len < 2)
		return (0);
	while (stack[i].edit == 0)
	{
		if (i == len - 2)
			return (0);
		i++;
	}
	tmp = stack[i].elem;
	stack[i].elem = stack[i + 1].elem;
	stack[i + 1].elem = tmp;
	return (1);
}

static int		ft_push(t_e *a_stack, t_e *b_stack, int len)
{
	int		i;
	int		tmp;

	i = 0;
	while (a_stack[i].edit == 0)
	{
		if (i == len - 1)
			return (0);
		i++;
	}
	tmp = a_stack[i].elem;
	a_stack[i].elem = 0;
	a_stack[i].edit = 0;
	i = 0;
	while (b_stack[i].edit == 0)
	{
		if (i == len)
			break ;
		i++;
	}
	b_stack[i - 1].elem = tmp;
	b_stack[i - 1].edit = 1;
	return (1);
}

static void		ft_rev_array(t_e *stack, int len)
{
	t_e		arr[len];
	int		i;

	i = 0;
	while (i < len)
	{
		arr[len - 1 - i].elem = stack[i].elem;
		arr[len - 1 - i].edit = stack[i].edit;
		i++;
	}
	i = 0;
	while (i < len)
	{
		stack[i].elem = arr[i].elem;
		stack[i].edit = arr[i].edit;
		i++;
	}
}

static int		ft_shift(t_e *stack, int len, int dir)
{
	int		i;
	int		tmp;

	i = 0;
	if (dir < 0)
		ft_rev_array(stack, len);
	while (stack[i].edit == 0)
	{
		if (i == len - 1)
			return (0);
		i++;
	}
	tmp = stack[i].elem;
	while (stack[i].edit != 0 && i <= len - 1)
	{
		stack[i].elem = stack[i + 1].elem;
		i++;
	}
	stack[i - 1].elem = tmp;
	if (dir < 0)
		ft_rev_array(stack, len);
	return (1);
}

void			ft_call_function(t_e *a_stack, t_e *b_stack, char *c, int len)
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
	else
	{
		if (!ft_strcmp(c, "rra\n") || !ft_strcmp(c, "rrr\n"))
			ft_shift(a_stack, len, -1);
		if (!ft_strcmp(c, "rrb\n") || !ft_strcmp(c, "rrr\n"))
			ft_shift(b_stack, len, -1);
	}
}
