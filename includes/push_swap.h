/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:43:22 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 21:45:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"
# include <stdio.h>

# define MAX(x, y) x > y ? x : y
# define MIN(x, y) x < y ? x : y

int		ft_select_median(t_stack *stack, int n);
int		ft_check_sort_stack(t_stack *stack, int dir);

int		ft_quick_select(int *stack, size_t len, int num);
char	*ft_quick_sort_a(t_stack *a_stack, t_stack *b_stack, size_t n);
char	*ft_bubble_sort(t_stack *stack, int n, int dir);

char	*ft_parse_string(char *res);

#endif
