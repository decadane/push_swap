/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:39:24 by marvin            #+#    #+#             */
/*   Updated: 2019/01/27 17:45:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_stack_spec_cases(t_stack *a_s, t_stack *b_s, char c)
{
	char	*res;

	res = ft_strnew(1);
	if (c == 'b' && b_s->elem[b_s->top] < b_s->elem[b_s->top + 1])
	{
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "sb\n")));
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "pa\n")));
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "pa\n")));
	}
	else if (c == 'b')
	{
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "pa\n")));
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "pa\n")));
	}
	if (a_s->elem[a_s->top] > a_s->elem[a_s->top + 1] && c == 'a')
		return (ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "sa\n"))));
	return (res);
}

char		*ft_quick_sort_b(t_stack *a_s, t_stack *b_s, size_t n)
{
	float	pivot;
	int		i;
	int		rot_count;
	int		push_count;
	char	*res;

	rot_count = 0;
	res = ft_strnew(1);
	push_count = 0;
	i = -1;
	if (n == 1)
		return (ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "pa\n"))));
	if (n == 2)
		return (ft_strjoin(res, ft_stack_spec_cases(a_s, b_s, 'b')));
	pivot = ft_select_median(b_s, n);
	while (++i < (int)n)
	{
		if (b_s->elem[b_s->top] < pivot && ++rot_count)
			res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "rb\n")));
		else if (++push_count)
			res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "pa\n")));
	}
	return (ft_strjoin(res, ft_split_sort_b(a_s, b_s, rot_count, push_count)));
}

char		*ft_split_sort_b(t_stack *a_s, t_stack *b_s, int rot_count,
		int push_count)
{
	int		i;
	char	*res;

	res = ft_strnew(1);
	if (push_count > 0)
		res = ft_strjoin(res, ft_quick_sort_a(a_s, b_s, push_count));
	i = -1;
	while (++i < rot_count)
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "rrb\n")));
	if (rot_count > 0)
		res = ft_strjoin(res, ft_quick_sort_b(a_s, b_s, rot_count));
	return (res);
}

static char	*ft_split_sort_a(t_stack *a_s, t_stack *b_s, int rot_count,
		int push_count)
{
	int		i;
	char	*res;

	res = ft_strnew(1);
	i = -1;
	while (++i < rot_count)
		res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "rra\n")));
	if (rot_count > 0)
		res = ft_strjoin(res, ft_quick_sort_a(a_s, b_s, rot_count));
	if (push_count > 0)
		res = ft_strjoin(res, ft_quick_sort_b(a_s, b_s, push_count));
	return (res);
}

char		*ft_quick_sort_a(t_stack *a_s, t_stack *b_s, size_t n)
{
	float	pivot;
	int		i;
	int		rot_count;
	int		push_count;
	char	*res;

	res = ft_strnew(1);
	rot_count = 0;
	push_count = 0;
	i = -1;
	if (n == 1)
		return (res);
	if (n == 2)
		return (ft_strjoin(res, ft_stack_spec_cases(a_s, b_s, 'a')));
	pivot = ft_select_median(a_s, n);
	while (++i < (int)n)
	{
		if (a_s->elem[a_s->top] < pivot && ++push_count)
			res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "pb\n")));
		else if (++rot_count)
			res = ft_strjoin(res, ft_strdup(ft_call_ft(a_s, b_s, "ra\n")));
	}
	return (ft_strjoin(res, ft_split_sort_a(a_s, b_s, rot_count, push_count)));
}
