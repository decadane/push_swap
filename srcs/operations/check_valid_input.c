/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:49:52 by marvin            #+#    #+#             */
/*   Updated: 2019/01/26 20:28:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_valid_input(char *str)
{
	int		i;
	long	tmp;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	tmp = ft_mini_atoi(str);
	if ((int)tmp != tmp || (tmp == 0 && *str != '0'))
		return (0);
	return (1);
}
