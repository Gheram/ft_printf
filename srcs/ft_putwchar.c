/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:30:33 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/28 14:44:32 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t element)
{
	if (element > 0x7f && element <= 0xff && MB_CUR_MAX != 4)
		ft_putchar_one(element);
	else if (element <= 0x7F)
		ft_putchar_one(element);
	else if (element <= 0x7FF)
	{
		ft_putchar_one((element >> 6) + 0xC0);
		ft_putchar_one((element & 0x3F) + 0x80);
	}
	else if (element <= 0XFFFF)
	{
		ft_putchar_one((element >> 12) + 0xE0);
		ft_putchar_one(((element >> 6) & 0x3F) + 0x80);
		ft_putchar_one((element & 0x3F) + 0x80);
	}
	else if (element <= 0x1FFFFF)
	{
		ft_putchar_one((element >> 18) + 0xF0);
		ft_putchar_one(((element >> 12) & 0x3F) + 0x80);
		ft_putchar_one(((element >> 6) & 0x3F) + 0x80);
		ft_putchar_one((element & 0x3F) + 0x80);
	}
}
