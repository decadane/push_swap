/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:39:24 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 13:25:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_quick_sort_b(t_stack *a_stack, t_stack *b_stack, size_t n)
{
	float	pivot;
	int		i;
	int		rot_count;
	int		push_count;

	rot_count = 0;
	push_count = 0;
	i = -1;
	if (n == 1)
	{
//		ft_print_stack(a_stack, b_stack);
//		getchar();
		ft_call_function(a_stack, b_stack, "pa");
		ft_putstr("pa\n");
		return (NULL);
	}
	if (n == 2)
	{
//		ft_print_stack(a_stack, b_stack);
//		getchar();
		if (b_stack->elem[b_stack->top] < b_stack->elem[b_stack->top + 1])
		{
			ft_call_function(a_stack, b_stack, "sb");
			ft_putstr("sb\n");
		}
		ft_call_function(a_stack, b_stack, "pa");
		ft_call_function(a_stack, b_stack, "pa");
		ft_putstr("pa\npa\n");
		return (ft_strdup(""));
	}
//	pivot = (b_stack->elem[b_stack->top] + b_stack->elem[b_stack->top + n - 1]) / 2.0;
	pivot = ft_select_median(b_stack, n);
//	printf("Pivot: %f\n", pivot);
	while (++i < (int)n)
	{
//		ft_print_stack(a_stack, b_stack);
//		getchar();
		if (b_stack->elem[b_stack->top] < pivot)
		{
			ft_call_function(a_stack, b_stack, "rb");
			ft_putstr("rb\n");
			rot_count++;
		}
		else
		{
			ft_call_function(a_stack, b_stack, "pa");
			ft_putstr("pa\n");
			push_count++;
		}
	}
//		ft_print_stack(a_stack, b_stack);
//		getchar();
	if (push_count > 0)
	{
		ft_quick_sort_a(a_stack, b_stack, push_count);
	}
	i = -1;
	while (++i < rot_count)
	{
		ft_call_function(a_stack, b_stack, "rrb");
		ft_putstr("rrb\n");
	}
	if (rot_count > 0)
	{
		ft_quick_sort_b(a_stack, b_stack, rot_count);
	}
	return (NULL);
}

char	*ft_quick_sort_a(t_stack *a_stack, t_stack *b_stack, size_t n)
{
	float	pivot;
	int		i;
	int		rot_count;
	int		push_count;

	rot_count = 0;
	push_count = 0;
	i = -1;
	if (n == 1)
		return (ft_strdup(""));
	if (n == 2)
	{
//		ft_print_stack(a_stack, b_stack);
//		getchar();
		if (a_stack->elem[a_stack->top] > a_stack->elem[a_stack->top + 1])
		{
			ft_call_function(a_stack, b_stack, "sa");
			ft_putstr("sa\n");
		}
		return (ft_strdup(""));
	}
//	pivot = (a_stack->elem[a_stack->top] + a_stack->elem[a_stack->top + n - 1]) / 2.0;
	pivot = ft_select_median(a_stack, n);
//	printf("Pivot: %f\n", pivot);
	while (++i < (int)n)
	{
//		ft_print_stack(a_stack, b_stack);
//		getchar();
		if (a_stack->elem[a_stack->top] < pivot)
		{
			ft_call_function(a_stack, b_stack, "pb");
			ft_putstr("pb\n");
			push_count++;
		}
		else
		{
			ft_call_function(a_stack, b_stack, "ra");
			ft_putstr("ra\n");
			rot_count++;
		}
	}
	i = 0;
	while (i < rot_count)
	{
		ft_call_function(a_stack, b_stack, "rra");
		ft_putstr("rra\n");
		i++;
	}
//		ft_print_stack(a_stack, b_stack);
//		getchar();
	if (rot_count > 0)
	{
		ft_quick_sort_a(a_stack, b_stack, rot_count);
	}
	if (push_count > 0)
	{
		ft_quick_sort_b(a_stack, b_stack, push_count);
	}
	return (NULL);
}
