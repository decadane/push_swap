/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:39:24 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 21:55:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_quick_sort_b(t_stack *a_stack, t_stack *b_stack, size_t n)
{
	float	pivot;
	int		i;
	int		rot_count;
	int		push_count;
	char	*res;

	rot_count = 0;
	res = ft_strnew(0);
	push_count = 0;
	i = -1;
	if (n == 1)
	{
		ft_call_function(a_stack, b_stack, "pa");
		res = ft_strjoin(res, ft_strdup("pa\n"));
		return (res);
	}
	pivot = ft_select_median(b_stack, n);
//	printf("Pivot: %f\n", pivot);
	while (++i < (int)n)
	{
//		ft_print_stack(a_stack, b_stack);
//		getchar();
		if (b_stack->elem[b_stack->top] < pivot)
		{
			ft_call_function(a_stack, b_stack, "rb");
			res = ft_strjoin(res, ft_strdup("rb\n"));
			rot_count++;
		}
		else
		{
			ft_call_function(a_stack, b_stack, "pa");
			res = ft_strjoin(res, ft_strdup("pa\n"));
			push_count++;
		}
	}
//		ft_print_stack(a_stack, b_stack);
//		getchar();
	if (push_count > 0)
		res = ft_strjoin(res, ft_quick_sort_a(a_stack, b_stack, push_count));
	i = -1;
	while (++i < rot_count)
	{
		ft_call_function(a_stack, b_stack, "rrb");
		res = ft_strjoin(res, ft_strdup("rrb\n"));
	}
	if (rot_count > 0)
		res = ft_strjoin(res, ft_quick_sort_b(a_stack, b_stack, rot_count));
	return (res);
}

char	*ft_quick_sort_a(t_stack *a_stack, t_stack *b_stack, size_t n)
{
	float	pivot;
	int		i;
	int		rot_count;
	int		push_count;
	char	*res;

	res = ft_strnew(0);
	rot_count = 0;
	push_count = 0;
	i = -1;
	if (n == 1)
		return (res);
	pivot = ft_select_median(a_stack, n);
//	printf("Pivot: %f\n", pivot);
	while (++i < (int)n)
	{
//		ft_print_stack(a_stack, b_stack);
//		getchar();
		if (a_stack->elem[a_stack->top] < pivot)
		{
			ft_call_function(a_stack, b_stack, "pb");
			res = ft_strjoin(res, ft_strdup("pb\n"));
			push_count++;
		}
		else
		{
			ft_call_function(a_stack, b_stack, "ra");
			res = ft_strjoin(res, ft_strdup("ra\n"));
			rot_count++;
		}
	}
	i = 0;
	while (i < rot_count)
	{
		ft_call_function(a_stack, b_stack, "rra");
		res = ft_strjoin(res, ft_strdup("rra\n"));
		i++;
	}
//		ft_print_stack(a_stack, b_stack);
//		getchar();
	if (rot_count > 0)
		res = ft_strjoin(res, ft_quick_sort_a(a_stack, b_stack, rot_count));
	if (push_count > 0)
		res = ft_strjoin(res, ft_quick_sort_b(a_stack, b_stack, push_count));
	return (res);
}
