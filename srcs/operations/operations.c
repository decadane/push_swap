/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:54:11 by marvin            #+#    #+#             */
/*   Updated: 2019/01/16 18:35:08 by marvin           ###   ########.fr       */
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
		if (i == len - 1)
			break ;
		i++;
	}
	b_stack[i] = tmp;
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

void			ft_call_function(int *a_stack, int *b_stack, char *cmd, int len)
{
	if (ft_strcmp(cmd, "ss") || ft_strcmp(cmd, "sa") || ft_strcmp(cmd, "sb"))
	{
		if (!ft_strcmp(cmd, "sb"))
			ft_swap(a_stack, len);
		if (!ft_strcmp(cmd, "sa"))
			ft_swap(b_stack, len);
	}
	if (ft_strcmp(cmd, "pa"))
		ft_push(b_stack, a_stack, len);
	if (ft_strcmp(cmd, "pb"))
		ft_push(a_stack, b_stack, len);
	if (ft_strcmp(cmd, "rr") || ft_strcmp(cmd, "ra") || ft_strcmp(cmd, "rb"))
	{
		if (!ft_strcmp(cmd, "rb"))
			ft_shift(a_stack, len, 1);
		if (!ft_strcmp(cmd, "ra"))
			ft_shift(b_stack, len, 1);
	}
	if (ft_strcmp(cmd, "rrr") || ft_strcmp(cmd, "rra") || ft_strcmp(cmd, "rrb"))
	{
		if (!ft_strcmp(cmd, "rrb"))
			ft_shift(a_stack, len, -1);
		if (!ft_strcmp(cmd, "rra"))
			ft_shift(b_stack, len, -1);
	}
}
