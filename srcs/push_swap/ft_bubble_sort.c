/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:23:07 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 21:55:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_a_sort(t_stack *stack, int dir, int limit)
{
	char	*res;

	res = ft_strnew(0);
//	ft_print(stack);
	while (!ft_check_sort_stack(stack, dir))
	{
		if (stack->elem[stack->top] > stack->elem[stack->top + 1]
				&& stack->elem[stack->top] != limit)
		{
			ft_call_function(stack, NULL, "sa");
			res = ft_strjoin(res, ft_strdup("sa\n"));
		}
		else
		{
			ft_call_function(stack, NULL, "ra");
			res = ft_strjoin(res, ft_strdup("ra\n"));
		}
	}
	return (res);
}

static char	*ft_b_sort(t_stack *stack, int dir, int limit)
{
	char	*res;

	res = ft_strnew(0);
//	ft_print(stack);
	while (!ft_check_sort_stack(stack, dir))
	{
		if (stack->elem[stack->top] < stack->elem[stack->top + 1]
				&& stack->elem[stack->top + 1] != limit)
		{
			ft_call_function(NULL, stack, "sb");
			res = ft_strjoin(res, ft_strdup("sb\n"));
		}
		else
		{
			ft_call_function(NULL, stack, "rrb");
			res = ft_strjoin(res, ft_strdup("rrb\n"));
		}
	}
	return (res);
}

char		*ft_bubble_sort(t_stack *stack, int n, int dir)
{
	char	*res;
	int		i;
	int		limit;

	i = -1;
	limit = -2147483648;
	while (++i < n)
	{
		if (stack->elem[stack->top + i] > limit)
			limit = stack->elem[stack->top + i];
	}
	res = ft_strnew(0);
	if (n == 1 || ft_check_sort_stack(stack, dir))
		return (res);
	if (dir > 0)
		res = ft_strjoin(res, ft_a_sort(stack, dir, limit));
	else
		res = ft_strjoin(res, ft_b_sort(stack, dir, limit));
	return (res);
}
