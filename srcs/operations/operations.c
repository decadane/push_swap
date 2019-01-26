/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:54:11 by marvin            #+#    #+#             */
/*   Updated: 2019/01/26 17:48:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int		ft_swap(t_stack *stack)
{
	int		tmp;
	int		i;

	i = 0;
	if (stack->size < 2 || stack->size - stack->top < 2)
		return (0);
	tmp = stack->elem[stack->top];
	stack->elem[stack->top] = stack->elem[stack->top + 1];
	stack->elem[stack->top + 1] = tmp;
	return (1);
}

static int		ft_push(t_stack *a_stack, t_stack *b_stack)
{
	int		tmp;

	if (a_stack->size < 1 || a_stack->size - a_stack->top < 1)
		return (0);
	tmp = a_stack->elem[a_stack->top];
	a_stack->elem[a_stack->top] = 0;
	a_stack->top++;
	b_stack->top--;
	b_stack->elem[b_stack->top] = tmp;
	return (1);
}

static int		ft_shift_up(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size < 2 || stack->size - stack->top < 2)
		return (0);
	tmp = stack->elem[stack->top];
	i = stack->top;
	while (i < stack->size - 1)
	{
		stack->elem[i] = stack->elem[i + 1];
		i++;
	}
	stack->elem[stack->size - 1] = tmp;
	return (1);
}

static int		ft_shift_down(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size < 2 || stack->size - stack->top < 2)
		return (0);
	tmp = stack->elem[stack->size - 1];
	i = stack->size;
	while (i > stack->top + 1)
	{
		stack->elem[i - 1] = stack->elem[i - 2];
		i--;
	}
	stack->elem[stack->top] = tmp;
	return (1);
}

char			*ft_call_ft(t_stack *a_stack, t_stack *b_stack, char *c)
{
	if (!ft_strcmp(c, "sa\n") || !ft_strcmp(c, "ss\n"))
		ft_swap(a_stack);
	if (!ft_strcmp(c, "sb\n") || !ft_strcmp(c, "ss\n"))
		ft_swap(b_stack);
	if (!ft_strcmp(c, "pa\n"))
		ft_push(b_stack, a_stack);
	if (!ft_strcmp(c, "pb\n"))
		ft_push(a_stack, b_stack);
	if (!ft_strcmp(c, "ra\n") || !ft_strcmp(c, "rr\n"))
		ft_shift_up(a_stack);
	if (!ft_strcmp(c, "rb\n") || !ft_strcmp(c, "rr\n"))
		ft_shift_up(b_stack);
	if (!ft_strcmp(c, "rra\n") || !ft_strcmp(c, "rrr\n"))
		ft_shift_down(a_stack);
	if (!ft_strcmp(c, "rrb\n") || !ft_strcmp(c, "rrr\n"))
		ft_shift_down(b_stack);
	return (c);
}
