/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:42:42 by ghtouman          #+#    #+#             */
/*   Updated: 2018/12/04 18:19:28 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

static void			charac_spf(intmax_t element, t_flags *flags)
{
	if (element >= 0 && !(flags->check_char & 0x08) && flags->check_char & 0x10)
	{
		ft_putchar_count(" ", 1);
		if (flags->width > 0)
			flags->width--;
	}
}

static int			size_float(long double element, unsigned int p)
{
	int				s;

	element < 0 ? element -= element : element;
	if (element <= 1)
		s = 1;
	else
		s = 0;
	while (element > 1)
	{
		element /= 10;
		s++;
	}
	s += p;
	if (p > 0)
		s++;
	return (s);
}

void				print_lf(long double element, t_flags flags)
{
	size_t			len;
	unsigned int	p;

	len = 1;
	p = 6;
	if (flags.check_flags & 0x04)
		p = flags.precision;
	if (flags.check_char & 0x01 && !(flags.check_char & 0x04))
		flags.w = '0';
	charac_spf((intmax_t)element, &flags);
	if (flags.w == '0' && flags.check_char & 0x08 && element > 0)
		ft_putchar_one('+');
	if (!(flags.check_char & 0x04))
		ft_print_width((intmax_t)element, flags, size_float(element, p));
	if (flags.w == ' ' && flags.check_char & 0x08 && element > 0)
		ft_putchar_one('+');
	ft_putfloat(element, &len, p);
	if (flags.check_char & 0x08 && element > 0)
		len++;
	if (flags.check_char & 0x04)
		ft_back_w((intmax_t)element, flags, len);
}

void				print_f(double element, t_flags flags)
{
	size_t			len;
	unsigned int	p;

	len = 1;
	p = 6;
	if (flags.check_flags & 0x04)
		p = flags.precision;
	if (flags.check_char & 0x01 && !(flags.check_char & 0x04))
		flags.w = '0';
	charac_spf((intmax_t)element, &flags);
	if (flags.w == '0' && flags.check_char & 0x08 && element > 0)
		ft_putchar_one('+');
	if (!(flags.check_char & 0x04))
		ft_print_width((intmax_t)element, flags, size_float(element, p));
	if (flags.w == ' ' && flags.check_char & 0x08 && element > 0)
		ft_putchar_one('+');
	ft_putfloat(element, &len, p);
	if (flags.check_char & 0x08 && element > 0)
		len++;
	if (flags.check_char & 0x04)
		ft_back_w((intmax_t)element, flags, len);
}
