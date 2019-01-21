/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:43:22 by marvin            #+#    #+#             */
/*   Updated: 2019/01/21 18:42:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"
# include <stdio.h>

# define MAX(x, y) x > y ? x : y
# define MIN(x, y) x < y ? x : y

int		ft_quick_select(int *stack, size_t len, int num);
char	*ft_quick_sort_a(t_stack *a_stack, t_stack *b_stack, size_t n);

#endif
