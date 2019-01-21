/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:30:10 by marvin            #+#    #+#             */
/*   Updated: 2019/01/21 19:56:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

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
	while ((int)++i < argc - 1)
	{
		if (ft_check_valid_input(argv[i + 1]))
		{
			a_stack->elem[i] = ft_mini_atoi(argv[i + 1]);
			a_stack->top--;
		}
		else
			return (ft_error_message());
		if (!ft_check_doubles(a_stack, a_stack->elem[i], i))
			return (ft_error_message());
	}
	res = ft_quick_sort_a(a_stack, b_stack, a_stack->size);
	ft_putstr(res);
	ft_print_stack(a_stack, b_stack);
	ft_delete_stacks(a_stack, b_stack);
	free(res);
	return (0);
}
