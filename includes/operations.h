/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:23:14 by marvin            #+#    #+#             */
/*   Updated: 2019/01/17 19:08:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"
# include <stdio.h>

typedef struct	s_stack_elem
{
	int			elem;
	int			edit;
}				t_e;

void			ft_call_function(t_e *a_stack, t_e *b_stack, char *command,
		int len);

void			ft_stack_init(t_e *a_stack, int len);
void			ft_print_stack(t_e *a_stack, t_e *b_stack, int len);
int				ft_mini_atoi(char *str);

#endif
