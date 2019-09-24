/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:37:17 by tigre             #+#    #+#             */
/*   Updated: 2018/11/28 18:05:08 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_lc(void *element, t_flags flags)
{
	wchar_t			gheram[2];

	gheram[0] = (wchar_t)element;
	gheram[1] = '\0';
	if (flags.check_flags & 0x08 && (!(flags.check_char & 0x04)))
		ft_width_unicode(flags, gheram);
	if ((gheram[0] >= 256 && MB_CUR_MAX != 4) || gheram[0] < 0x0 ||
	(gheram[0] >= 0xd800 && gheram[0] <= 0xdfff) || (gheram[0] > 0x10ffff))
	{
		g_ret = -1;
		return ;
	}
	else if (gheram[0] > 0x7f && gheram[0] <= 0xff && MB_CUR_MAX != 4)
		ft_putchar_one(gheram[0]);
	else
		ft_putwchar(gheram[0]);
	if (flags.check_char & 0x04 && flags.check_flags & 0x08)
	{
		ft_width_unicode(flags, &gheram[0]);
	}
}

static void			uni_p(wchar_t *str, t_flags flags)
{
	size_t			i;
	size_t			weight;
	long int		p;

	i = -1;
	p = (long int)flags.precision;
	while (str[++i] && p > 0)
	{
		weight = ft_weight_wchar(str[i]);
		p >= (long)weight ? ft_putwchar(str[i]) : p;
		p = p - weight;
	}
}

void				print_ls(void *element, t_flags flags)
{
	wchar_t			*str;

	if (!(str = (wchar_t*)element))
		return (ft_putchar_count("(null)", 6));
	if (ft_str_unicode_error((wchar_t*)element, flags.precision))
	{
		g_ret = -1;
		return ;
	}
	if (flags.check_flags & 0x08 && (!(flags.check_char & 0x04)))
		ft_width_unicode(flags, str);
	if (flags.check_flags & 0x04)
		uni_p(str, flags);
	else
		ft_putwstr((wchar_t*)element);
	if (flags.check_flags & 0x08 && flags.check_char & 0x04)
		ft_width_unicode(flags, str);
}
