/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:20:32 by ghtouman          #+#    #+#             */
/*   Updated: 2018/12/04 20:18:49 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

static void		calc_p(char *str, int i, int *p)
{
	*p = 0;
	while (str[i] >= '0' && str[i] <= '9')
		*p = *p * 10 + (str[i++] - '0');
}

static int		back(char *format, int i, int *p)
{
	int			back;

	back = 0;
	while (format[i] != '%')
	{
		if (format[i] == '.')
			calc_p(format + 1, i, p);
		if (format[i] == 'l' && format[i - 1] != 'l')
			back = 1;
		if (format[i] == 'l' && format[i - 1] == 'l' && back != 1)
			back = 0;
		i--;
	}
	return (back);
}

static int		ft_check_if_unicode(char *f, int i, va_list ap)
{
	void		*element;
	int			j;
	int			s;
	int			p;

	j = -1;
	s = 0;
	p = -5;
	while (g_specifier[++j].flag_s)
	{
		if (g_specifier[j].flag_s == f[i] && j < 15)
		{
			element = va_arg(ap, void*);
			s = 2;
		}
	}
	if (f[i] == 'c' && (back(f, i, &p) == 1))
		return (ft_unicode_error((wchar_t)element));
	if ((f[i] == 's') && (back(f, i, &p) == 1))
		return (ft_str_unicode_error((wchar_t*)element, p));
	if (f[i] == 'C')
		return (ft_unicode_error((wchar_t)element));
	if (f[i] == 'S')
		return (ft_str_unicode_error((wchar_t*)element, p));
	return (s);
}

int				ft_found_unicode(va_list ap, const char *format, int *num_var)
{
	int			i;
	int			back;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			format[i] == '%' ? i++ : i;
			while (format[i++])
			{
				back = (ft_check_if_unicode((char*)format, i - 1, ap));
				if (back == 1)
					return (1);
				if (back == 2)
				{
					(*num_var)++;
					break ;
				}
			}
		}
		i++;
	}
	return (0);
}
