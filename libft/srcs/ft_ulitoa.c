/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:01:50 by marvin            #+#    #+#             */
/*   Updated: 2018/12/22 21:46:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long long n)
{
	int		count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	ft_get_char(unsigned long long n, int len)
{
	return ((n / ft_power(10, len - 1)) % 10 + '0');
}

static char	*ft_get_str(unsigned long long n, int len, char *head)
{
	char	*result;

	result = head;
	while (len > 0)
	{
		*head = ft_get_char(n, len);
		len--;
		head++;
	}
	*head = '\0';
	return (result);
}

char		*ft_ulitoa(unsigned long long n)
{
	int		len;
	char	*result;

	len = ft_count(n);
	if (!(result = (char*)malloc(len + 1)))
		return (NULL);
	return (ft_get_str(n, len, result));
}
