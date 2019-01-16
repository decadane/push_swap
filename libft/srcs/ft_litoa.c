/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:09:00 by marvin            #+#    #+#             */
/*   Updated: 2019/01/02 14:26:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long long n)
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

static char	ft_get_char(long long n, int len)
{
	return ((n / ft_power(10, len - 1)) % 10 + '0');
}

static char	*ft_get_str(long long n, int len, char *head)
{
	char	*result;

	result = head;
	if (*head == '-')
		head++;
	while (len > 0)
	{
		*head = ft_get_char(n, len);
		len--;
		head++;
	}
	*head = '\0';
	return (result);
}

char		*ft_litoa(long long n, int *neg)
{
	int		len;
	char	*result;

	len = ft_count(n);
	result = ft_strnew(len);
	if (n < 0)
	{
		n *= -1;
		(*neg)++;
	}
	result = ft_get_str(n, len, result);
	return (result);
}
