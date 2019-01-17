/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:54:58 by marvin            #+#    #+#             */
/*   Updated: 2019/01/17 15:13:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "operations.h"

int				ft_check_valid_input(char *str);
int				ft_check_doubles(t_e *stack, int num, int len);
void			ft_check_sort(t_e *a_stack, t_e *b_stack, int len);

#endif