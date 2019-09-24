/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weight_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:13:55 by tigre             #+#    #+#             */
/*   Updated: 2018/11/28 14:44:01 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unicode_error(wchar_t element)
{
	if ((element > 255 && MB_CUR_MAX != 4) || element < 0x0 ||
			(element >= 0xd800 && element <= 0xdfff) || (element > 0x10ffff))
		return (1);
	return (2);
}

int			ft_str_unicode_error(wchar_t *str, int p)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (p > 0)
			{
				p -= ft_weight_wchar(str[i]);
				if (p <= 0 && p > -5)
					return (0);
			}
			if (ft_unicode_error(str[i]) == 1)
				return (1);
			i++;
		}
		return (0);
	}
	return (0);
}

size_t		ft_weight_wchar(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	if (c > 0x7f && c <= 0xff && MB_CUR_MAX != 4)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0XFFFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
	return (0);
}

size_t		ft_strwlen(wchar_t *str)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (str[i])
		len += ft_weight_wchar(str[i++]);
	return (len);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
