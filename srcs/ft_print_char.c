/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:19:37 by ghtouman          #+#    #+#             */
/*   Updated: 2018/12/04 20:55:10 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_c(void *element, t_flags flags)
{
	if (flags.index_m == 1)
	{
		print_lc(element, flags);
		return ;
	}
	if (!(flags.check_char & 0x04))
		ft_print_width_s(flags, 1);
	ft_putchar_one((char)element);
	if (flags.check_char & 0x04)
		ft_print_width_s(flags, 1);
}

void				print_s(void *element, t_flags flags)
{
	char			*str;
	unsigned int	tmp;

	tmp = flags.precision;
	if (flags.index_m == 1)
		return (print_ls(element, flags));
	if (!(str = (char*)element))
		return (ft_putchar_null(flags));
	if (flags.check_flags & 0x08 && flags.check_flags & 0x04
	&& flags.precision == 0)
		return (ft_print_width_s(flags, 0));
	if (!(flags.check_char & 0x04))
		ft_print_width_s(flags, ft_strlen(str));
	if (flags.check_flags & 0x04 && flags.precision == 0)
		return (ft_print_width_s(flags, tmp));
	if (*str && flags.precision > 0 && flags.precision < ft_strlen(str))
	{
		while (*str && flags.precision-- > 0)
			ft_putchar_count(str++, 1);
		flags.check_char & 0x04 ? ft_print_width_s(flags, tmp) : str;
		return ;
	}
	ft_putchar_count(str, ft_strlen(str));
	if (flags.check_char & 0x04)
		ft_print_width_s(flags, ft_strlen(str));
}

void				print_percent(void *element, t_flags flags)
{
	(void)element;
	(void)flags;
	if (!(flags.check_char & 0x04))
		ft_print_width_s(flags, 1);
	ft_putchar_one('%');
	if (flags.check_char & 0x04)
		ft_print_width_s(flags, 1);
}
