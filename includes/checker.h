/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:54:58 by marvin            #+#    #+#             */
/*   Updated: 2019/01/21 18:43:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "operations.h"
# include "get_next_line.h"

int				get_next_line(const int fd, char **line);

int				ft_check_valid_input(char *str);
int				ft_check_doubles(t_stack *stack, int num, size_t i);
void			ft_check_sort(t_stack *a_stack, t_stack *b_stack);

#endif
