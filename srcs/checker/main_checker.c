/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:45:33 by marvin            #+#    #+#             */
/*   Updated: 2019/01/16 21:27:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "checker.h"

static int		ft_error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

static void		ft_exec_commands(int *a_stack, int *b_stack, int len)
{
	char	cmd[5];
	int		i;

	i = 0;
	ft_bzero(cmd, 5);
	while (1)
	{
		read(0, cmd, 5);
		if (cmd[0] == '\n')
			break ;
		else
		{
			ft_call_function(a_stack, b_stack, cmd, len);
		}
	}
}

int				main(int argc, char *argv[])
{
	int		a_stack[argc - 1];
	int		b_stack[argc - 1];
	int		i;

	if (argc < 2)
		return (ft_error_message());
	i = 0;
	ft_stack_init(b_stack, argc - 1);
	while (i < argc - 1)
	{
		a_stack[i] = ft_check_valid_input(argv[i + 1]);
		if (a_stack[i] == 0 || !ft_check_doubles(a_stack, a_stack[i], i))
			return (ft_error_message());
		i++;
	}
	ft_exec_commands(a_stack, b_stack, argc - 1);
	ft_print_stack(a_stack, b_stack, argc - 1);
	return (0);
}
