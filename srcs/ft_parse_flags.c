/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:31:27 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/29 20:21:35 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_comb(char **str, t_flags *flags)
{
	char		*out;

	*flags = (t_flags){0, 0, -1, 0, 0, ' ', 0};
	while (!(flags->check_flags & 0x01))
	{
		out = *str;
		ft_check_characters(flags, str);
		ft_check_width(flags, str);
		ft_check_precision(flags, str);
		ft_check_modifier(flags, str);
		if (**str == '\0')
			return (1);
		ft_check_specifier(flags, *str);
		if (out == *str && !(flags->check_flags & 0x01))
			break ;
	}
	return (0);
}

static int		ft_flag_checker(char **str, t_flags *flags, va_list ap, int *n)
{
	if (ft_comb(str, flags))
		return (1);
	if (**str && !(flags->check_flags & 0x01) && !(flags->check_flags & 0x08))
		ft_putchar_count(*str, 1);
	else
	{
		ft_control(*flags, ap);
		*n != -2 ? (*n)-- : *n;
		if (!(flags->check_flags & 0x01) && flags->check_flags & 0x08)
		{
			ft_putchar_one(**str);
			if (flags->check_char & 0x04 && flags->check_flags & 0x08)
				while (--flags->width)
					ft_putchar_one(flags->w);
		}
	}
	return (0);
}

int				ft_parse_flags(const char *format, va_list ap, int num_var)
{
	char		*tmp;
	t_flags		flags;

	tmp = (char*)format;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			if (*tmp == '%')
				ft_putchar_count("%", 1);
			else if (ft_flag_checker(&tmp, &flags, ap, &num_var))
				return (0);
		}
		else if (num_var == -2)
			ft_putchar_count(tmp, 1);
		else if (num_var >= -1)
		{
			if (num_var <= 0)
				return (g_ret = -1);
			ft_putchar_one(*tmp);
		}
		tmp++;
	}
	return (0);
}
