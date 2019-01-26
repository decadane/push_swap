/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:30:10 by marvin            #+#    #+#             */
/*   Updated: 2019/01/26 19:37:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

static void		ft_print_string(char *str)
{
	str = ft_parse_string(str);
	ft_putstr(str);
	free(str);
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
	if (!(ft_check_sort_stack(a_stack, 1, a_stack->size)))
		ft_print_string(ft_quick_sort_a(a_stack, b_stack, a_stack->size));
	ft_delete_stacks(a_stack, b_stack);
	return (0);
}
