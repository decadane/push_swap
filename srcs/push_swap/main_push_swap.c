/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:30:10 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 21:55:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

static void		ft_print_string(char *str)
{
	str = ft_parse_string(str);
	ft_putstr(str);
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
	char		*res[2];

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
//	ft_print_stack(a_stack, b_stack);
	if (argc - 1 < 10)
	{
		res[1] = ft_bubble_sort(ft_copy_stack(a_stack), a_stack->size, 1);
		res[0] = ft_quick_sort_a(a_stack, b_stack, a_stack->size);
		if (ft_strlen(res[0]) > ft_strlen(res[1]))
			ft_print_string(res[1]);
		else
			ft_print_string(res[0]);
	}
	else
	{
		res[1] = ft_quick_sort_a(a_stack, b_stack, a_stack->size);
		ft_print_string(res[1]);
	}
//	ft_print_stack(a_stack, b_stack);
	ft_delete_stacks(a_stack, b_stack);
	free(res[0]);
	free(res[1]);
	return (0);
}
