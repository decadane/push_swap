/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:45:33 by marvin            #+#    #+#             */
/*   Updated: 2019/01/21 19:59:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "checker.h"

static int		ft_check_command(char *cmd)
{
	return (!ft_strcmp(cmd, "sa") ||
		!ft_strcmp(cmd, "sb") ||
		!ft_strcmp(cmd, "ss") ||
		!ft_strcmp(cmd, "pa") ||
		!ft_strcmp(cmd, "pb") ||
		!ft_strcmp(cmd, "ra") ||
		!ft_strcmp(cmd, "rb") ||
		!ft_strcmp(cmd, "rr") ||
		!ft_strcmp(cmd, "rra") ||
		!ft_strcmp(cmd, "rrb") ||
		!ft_strcmp(cmd, "rrr"));
}

static int		ft_error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

static int		ft_exec_commands(t_stack *a_stack, t_stack *b_stack)
{
	char	*cmd;

	while (get_next_line(0, &cmd))
	{
		if (ft_check_command(cmd))
			ft_call_function(a_stack, b_stack, cmd);
		else
			return (ft_error_message());
	}
	ft_check_sort(a_stack, b_stack);
	return (0);
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
	if (ft_exec_commands(a_stack, b_stack) == -1)
		return (-1);
	ft_print_stack(a_stack, b_stack);
	ft_delete_stacks(a_stack, b_stack);
	return (0);
}
