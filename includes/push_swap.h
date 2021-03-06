/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:43:22 by marvin            #+#    #+#             */
/*   Updated: 2019/01/27 16:51:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"

# define MAX(x, y) x > y ? x : y
# define MIN(x, y) x < y ? x : y

int		ft_select_median(t_stack *stack, int n);
int		ft_check_sort_stack(t_stack *stack, int dir, int n);

char	*ft_quick_sort_a(t_stack *a_stack, t_stack *b_stack, size_t n);
char	*ft_bubble_sort(t_stack *a_stack, t_stack *b_stack);
char	*ft_split_sort_b(t_stack *a_s, t_stack *b_s, int rot_count,
		int push_count);

char	*ft_parse_string(char *res);

#endif
