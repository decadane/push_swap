/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:30:10 by marvin            #+#    #+#             */
/*   Updated: 2019/01/27 17:42:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"
#include <stdio.h>

static void		ft_print_string(char *str)
{
	str = ft_parse_string(str);
	ft_putstr(str);
	free(str);
}

static char		*ft_choose_solv(t_stack *a_stack, t_stack *b_stack)
{
	char	*bubble_res;
	char	*q_res;
	char	*res;

	if (ft_check_sort_stack(a_stack, 1, a_stack->size))
		return (ft_strdup(""));
	if (a_stack->size < 10 && a_stack->size > 2)
	{
		bubble_res = ft_bubble_sort(a_stack, b_stack);
		q_res = ft_parse_string(ft_quick_sort_a(a_stack,
					b_stack, a_stack->size));
		if (ft_count_symb(bubble_res, '\n') > ft_count_symb(q_res, '\n'))
		{
			res = q_res;
			free(bubble_res);
		}
		else
		{
			res = bubble_res;
			free(q_res);
		}
	}
	else
		res = ft_quick_sort_a(a_stack, b_stack, a_stack->size);
	return (res);
}

static int		ft_error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int				main(int argc, char *argv[])
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	size_t		i;
	char		*res;

	if (argc < 2)
		return (0);
	i = -1;
	a_stack = ft_stack_init(argc - 1);
	b_stack = ft_stack_init(argc - 1);
	if (argv[1][0] == '-' && argv[1][1] == 'v')
		argv++;
	while ((int)++i < argc - 1)
	{
		if (ft_check_valid_input(argv[i + 1]) && a_stack->top--)
			a_stack->elem[i] = ft_mini_atoi(argv[i + 1]);
		else
			return (ft_error_message());
		if (!ft_check_doubles(a_stack, a_stack->elem[i], i))
			return (ft_error_message());
	}
	res = ft_choose_solv(a_stack, b_stack);
	ft_print_string(res);
	ft_delete_stacks(a_stack, b_stack);
	return (0);
}
