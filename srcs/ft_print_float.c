/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:44:35 by ghtouman          #+#    #+#             */
/*   Updated: 2018/12/04 20:48:55 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_decimal(double f, size_t *len, unsigned int p)
{
	double u;

	(*len)++;
	while (p--)
		f *= 10;
	u = f - (uintmax_t)f;
	if (u * 10 > 4)
		f++;
	return ((uintmax_t)f);
}

static uintmax_t	get_ldecimal(long double f, size_t *len, unsigned int p)
{
	long double		u;

	(*len)++;
	while (p--)
		f *= 10;
	u = f - (uintmax_t)f;
	if (u * 10 > 4)
		f++;
	return ((uintmax_t)f);
}

void				ft_putfloat(double f, size_t *len, unsigned int p)
{
	uintmax_t		n;

	if (f < 0)
	{
		(*len)++;
		ft_putchar_one('-');
		f = -f;
	}
	n = (uintmax_t)f;
	n != 0 ? f -= n : f;
	f >= 0.5 && p == 0 ? n++ : n;
	ft_putlnbr(n, len);
	if (p)
	{
		ft_putchar_one('.');
		(*len)++;
		if (f > 0)
			ft_putlnbr(get_decimal(f, len, p), len);
		else
		{
			(*len) += p;
			while (p--)
				ft_putchar_one('0');
		}
	}
}

void				ft_putlfloat(long double f, size_t *len, unsigned int p)
{
	uintmax_t		n;

	if (f < 0)
	{
		(*len)++;
		ft_putchar_one('-');
		f = -f;
	}
	n = (uintmax_t)f;
	n != 0 ? f -= n : f;
	f >= 0.5 && p == 0 ? n++ : n;
	ft_putlnbr(n, len);
	if (p)
	{
		ft_putchar_one('.');
		(*len)++;
		if (f > 0)
			ft_putlnbr(get_ldecimal(f, len, p), len);
		else
		{
			(*len) += p;
			while (p--)
				ft_putchar_one('0');
		}
	}
}
