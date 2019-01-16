/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:23:14 by marvin            #+#    #+#             */
/*   Updated: 2019/01/16 17:55:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"
# include <stdio.h>

void	ft_call_function(int *a_stack, int *b_stack, char *command, int len);

void	ft_print_stack(int *a_stack, int *b_stack, int len);

#endif
