/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:31:44 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/30 14:24:15 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width(t_flags *flags, char **str)
{
	if (**str < '0' || **str > '9')
		return ;
	flags->width = 0;
	while (**str >= '0' && **str <= '9')
	{
		flags->width = flags->width * 10 + (**str - '0');
		(*str)++;
	}
	flags->check_flags |= 0x08;
	if (flags->width == 0)
		(*str)++;
}

int		ft_print_width_u(uintmax_t elem, t_flags flags, int len)
{
	long int tmp;

	tmp = 0;
	if (flags.width <= flags.precision)
		return (0);
	if ((flags.index_s == 3 || flags.index_s == 4) && flags.check_char & 0x02 &&
		elem > 0)
		flags.width--;
	if ((flags.index_s == 7 || flags.index_s == 8) && flags.check_char & 0x02 &&
		elem > 0)
		flags.width -= 2;
	if (flags.precision > (unsigned int)len)
		tmp = flags.precision - len;
	if (flags.width > 0)
		tmp = (long int)flags.width - len - tmp;
	while (tmp > 0)
	{
		ft_putchar_count(&flags.w, 1);
		tmp--;
	}
	return (0);
}

void	ft_print_width(intmax_t element, t_flags flags, int len)
{
	long int tmp;

	tmp = 0;
	if (flags.width <= flags.precision)
		return ;
	if (element >= 0 && flags.check_char & 0x08)
		flags.width--;
	if (element < 0 && flags.check_char & 0x01 && flags.check_flags & 0x04)
		flags.width--;
	if (element < 0 && len < (long int)flags.precision + 1)
		flags.width--;
	if (flags.precision > (unsigned int)len)
		tmp = flags.precision - len;
	if (flags.width > 0)
		tmp = (long int)flags.width - len - tmp;
	while (tmp > 0)
	{
		ft_putchar_count(&flags.w, 1);
		tmp--;
	}
}

void	ft_print_width_s(t_flags flags, size_t len)
{
	long int tmp;

	tmp = 0;
	if (flags.width < len && flags.width < flags.precision)
		return ;
	if (flags.width > 0 && flags.check_flags & 0x04 && flags.precision <= len)
		tmp = (long int)flags.width - (long int)flags.precision;
	else
		tmp = (long int)flags.width - len;
	if (flags.check_flags & 0x04 && flags.index_s != 12)
		flags.precision == 0 ? tmp-- : tmp;
	while (tmp > 0)
	{
		ft_putchar_count(&flags.w, 1);
		tmp--;
	}
}

void	ft_width_unicode(t_flags flags, wchar_t *str)
{
	int		weight;

	weight = 0;
	if (flags.width <= flags.precision)
		return ;
	if (flags.check_flags & 0x04)
	{
		while (*str && flags.precision > (unsigned int)weight)
			weight += ft_weight_wchar(*(str++));
		if ((unsigned int)weight > flags.precision)
			weight -= ft_weight_wchar(*(--str));
		flags.width -= weight;
		while (flags.width--)
			ft_putchar_count(&flags.w, 1);
		return ;
	}
	while (*str)
		weight += ft_weight_wchar(*(str++));
	if ((unsigned int)weight < flags.width)
	{
		flags.width -= weight;
		while (flags.width--)
			ft_putchar_count(&flags.w, 1);
	}
}
