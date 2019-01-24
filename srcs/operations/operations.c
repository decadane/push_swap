/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:54:11 by marvin            #+#    #+#             */
/*   Updated: 2019/01/24 21:13:55 by marvin           ###   ########.fr       */
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

	if (stack->size < 2)
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

	if (stack->size < 2)
		return (0);
	tmp = stack->elem[stack->size - 1];
	i = stack->size;
	while (i > stack->top)
	{
		stack->elem[i] = stack->elem[i - 1];
		i--;
	}
	stack->elem[stack->top] = tmp;
	return (1);
}

void			ft_call_function(t_stack *a_stack, t_stack *b_stack, char *c)
{
	if (!ft_strcmp(c, "ss") || !ft_strcmp(c, "sa") || !ft_strcmp(c, "sb"))
	{
		if (!ft_strcmp(c, "sa") || !ft_strcmp(c, "ss"))
			ft_swap(a_stack);
		if (!ft_strcmp(c, "sb") || !ft_strcmp(c, "ss"))
			ft_swap(b_stack);
	}
	if (!ft_strcmp(c, "pa"))
		ft_push(b_stack, a_stack);
	if (!ft_strcmp(c, "pb"))
		ft_push(a_stack, b_stack);
	if (!ft_strcmp(c, "rr") || !ft_strcmp(c, "ra") || !ft_strcmp(c, "rb"))
	{
		if (!ft_strcmp(c, "ra") || !ft_strcmp(c, "rr"))
			ft_shift_up(a_stack);
		if (!ft_strcmp(c, "rb") || !ft_strcmp(c, "rr"))
			ft_shift_up(b_stack);
	}
	else
	{
		if (!ft_strcmp(c, "rra") || !ft_strcmp(c, "rrr"))
			ft_shift_down(a_stack);
		if (!ft_strcmp(c, "rrb") || !ft_strcmp(c, "rrr"))
			ft_shift_down(b_stack);
	}
}
