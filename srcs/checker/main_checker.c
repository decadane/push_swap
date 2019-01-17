/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:45:33 by marvin            #+#    #+#             */
/*   Updated: 2019/01/17 19:24:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "checker.h"

static int		ft_check_command(char *cmd)
{
	return (!ft_strcmp(cmd, "sa\n") ||
		!ft_strcmp(cmd, "sb\n") ||
		!ft_strcmp(cmd, "ss\n") ||
		!ft_strcmp(cmd, "pa\n") ||
		!ft_strcmp(cmd, "pb\n") ||
		!ft_strcmp(cmd, "ra\n") ||
		!ft_strcmp(cmd, "rb\n") ||
		!ft_strcmp(cmd, "rr\n") ||
		!ft_strcmp(cmd, "rra\n") ||
		!ft_strcmp(cmd, "rrb\n") ||
		!ft_strcmp(cmd, "rrr\n"));
}

static int		ft_error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

static int		ft_exec_commands(t_e *a_stack, t_e *b_stack, int len)
{
	char	cmd[5];
	int		i;

	ft_bzero(cmd, 5);
	while (1)
	{
		i = 0;
		while (i < 5)
		{
			read(0, &(cmd[i]), 1);
			if (cmd[i] == '\n')
				break ;
			i++;
		}
		if (*cmd == '\n')
			break ;
		if (ft_check_command(cmd))
			ft_call_function(a_stack, b_stack, cmd, len);
		else
			return (ft_error_message());
	}
	ft_check_sort(a_stack, b_stack, len);
	return (0);
}

int				main(int argc, char *argv[])
{
	t_e		a_stack[argc - 1];
	t_e		b_stack[argc - 1];
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	ft_stack_init(b_stack, argc - 1);
	while (i < argc - 1)
	{
		a_stack[i].elem = ft_check_valid_input(argv[i + 1]);
		if (!ft_check_doubles(a_stack, a_stack[i].elem, i))
			return (ft_error_message());
		else
			a_stack[i].edit = 1;
		i++;
	}
	if (ft_exec_commands(a_stack, b_stack, argc - 1) == -1)
		return (-1);
	ft_print_stack(a_stack, b_stack, argc - 1);
	return (0);
}
