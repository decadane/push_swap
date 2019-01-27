/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:23:14 by marvin            #+#    #+#             */
/*   Updated: 2019/01/27 14:42:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"

typedef struct	s_stack
{
	int			*elem;
	size_t		top;
	size_t		size;
}				t_stack;

char			*ft_call_ft(t_stack *a_stack, t_stack *b_stack, char *c);

t_stack			*ft_copy_stack(t_stack *stack);
t_stack			*ft_stack_init(size_t len);
void			ft_delete_stacks(t_stack *a_stack, t_stack *b_stack);
void			ft_print_stack(t_stack *a_stack, t_stack *b_stack);
int				ft_mini_atoi(char *str);

#endif
