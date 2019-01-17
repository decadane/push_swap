/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:03:39 by marvin            #+#    #+#             */
/*   Updated: 2019/01/17 19:10:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

int		ft_unicode_convert(char *out, wchar_t utf)
{
	int		i;

	i = 0;
	if (utf <= 0x7F)
		out[i++] = (char)utf;
	else if (utf <= 0x07FF)
	{
		out[i++] = (char)(((utf >> 6) & 0x1F) | 0xC0);
		out[i++] = (char)(((utf >> 0) & 0x3F) | 0x80);
	}
	else if (utf <= 0xFFFF)
	{
		out[i++] = (char)(((utf >> 12) & 0x0F) | 0xE0);
		out[i++] = (char)(((utf >> 6) & 0x3F) | 0x80);
		out[i++] = (char)(((utf >> 0) & 0x3F) | 0x80);
	}
	else if (utf <= 0x10FFFF)
	{
		out[i++] = (char)(((utf >> 18) & 0x07) | 0xF0);
		out[i++] = (char)(((utf >> 12) & 0x3F) | 0x80);
		out[i++] = (char)(((utf >> 6) & 0x3F) | 0x80);
		out[i++] = (char)(((utf >> 0) & 0x3F) | 0x80);
	}
	return (i);
}
