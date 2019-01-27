/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:33:58 by marvin            #+#    #+#             */
/*   Updated: 2019/01/27 17:39:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_forward(t_stack *a_stack)
{
	int		i;
	int		tmp;
	char	*res;

	i = -1;
	res = ft_strnew(1);
	tmp = a_stack->elem[0];
	while (++i < (int)a_stack->size)
	{
		if (tmp < a_stack->elem[i])
			tmp = a_stack->elem[i];
	}
	while (!(ft_check_sort_stack(a_stack, 1, a_stack->size - 1)))
	{
		if (a_stack->elem[a_stack->top] > a_stack->elem[a_stack->top + 1] &&
				a_stack->elem[a_stack->top] != tmp)
			res = ft_strjoin(res, ft_strdup(ft_call_ft(a_stack, NULL, "sa\n")));
		else
			res = ft_strjoin(res, ft_strdup(ft_call_ft(a_stack, NULL, "ra\n")));
	}
	ft_delete_stacks(a_stack, NULL);
	return (res);
}

static char	*ft_backward(t_stack *a_stack)
{
	int		i;
	int		tmp;
	char	*r;

	i = -1;
	r = ft_strnew(1);
	tmp = a_stack->elem[0];
	while (++i < (int)a_stack->size)
	{
		if (tmp < a_stack->elem[i])
			tmp = a_stack->elem[i];
	}
	while (!(ft_check_sort_stack(a_stack, 1, a_stack->size - 1)))
	{
		if (a_stack->elem[a_stack->top] > a_stack->elem[a_stack->top + 1] &&
				a_stack->elem[a_stack->top] != tmp)
			r = ft_strjoin(r, ft_strdup(ft_call_ft(a_stack, NULL, "sa\n")));
		else
			r = ft_strjoin(r, ft_strdup(ft_call_ft(a_stack, NULL, "rra\n")));
	}
	ft_delete_stacks(a_stack, NULL);
	return (r);
}

static char	*ft_scroll_stack(t_stack *stack, int i)
{
	char	*res;
	int		tmp;

	tmp = stack->elem[i];
	res = ft_strnew(1);
	if (i < (int)stack->size - 2 - (int)stack->top)
	{
		while (stack->elem[stack->top] != tmp)
			res = ft_strjoin(res, ft_strdup(ft_call_ft(stack, NULL, "ra\n")));
	}
	else
	{
		while (stack->elem[stack->top] != tmp)
			res = ft_strjoin(res, ft_strdup(ft_call_ft(stack, NULL, "rra\n")));
	}
	return (res);
}

static char	*ft_stacking(t_stack *a_stack, t_stack *b_stack)
{
	int		i;
	int		tmp;
	char	*res;

	res = ft_strnew(1);
	while (a_stack->top < a_stack->size - 1)
	{
		i = -1;
		tmp = a_stack->top;
		while (++i < (int)a_stack->size - (int)a_stack->top)
		{
			if (a_stack->elem[tmp] > a_stack->elem[i + a_stack->top])
				tmp = i + a_stack->top;
		}
		res = ft_strjoin(res, ft_scroll_stack(a_stack, tmp));
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_stack, b_stack, "pb\n")));
	}
	while (b_stack->top < b_stack->size)
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_stack, b_stack, "pa\n")));
	ft_delete_stacks(a_stack, b_stack);
	return (res);
}

char		*ft_bubble_sort(t_stack *a_stack, t_stack *b_stack)
{
	char	*res[3];
	int		len;

	res[0] = ft_forward(ft_copy_stack(a_stack));
	len = ft_count_symb(res[0], '\n');
	res[1] = ft_backward(ft_copy_stack(a_stack));
	if (ft_count_symb(res[1], '\n') > len)
		free(res[1]);
	else
	{
		free(res[0]);
		res[0] = res[1];
		len = ft_count_symb(res[0], '\n');
	}
	res[2] = ft_stacking(ft_copy_stack(a_stack), ft_copy_stack(b_stack));
	if (ft_count_symb(res[2], '\n') > len)
		free(res[2]);
	else
	{
		free(res[0]);
		res[0] = res[2];
	}
	return (res[0]);
}
