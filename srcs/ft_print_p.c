/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:20:58 by tigre             #+#    #+#             */
/*   Updated: 2018/11/28 15:19:57 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

static size_t	ft_len_number_b(unsigned long n, unsigned int b, size_t len)
{
	while (n >= b)
	{
		len++;
		n = n / b;
	}
	return (len);
}

static void		print_width_p(long int tmp, t_flags flags, size_t l)
{
	tmp = (long int)flags.width - tmp - l - 2;
	while (tmp-- > 0)
		ft_putchar_count(&flags.w, 1);
}

void			print_p(void *element, t_flags flags)
{
	long int	tmp;
	size_t		l;

	l = ft_len_number_b((unsigned long)element, 16, 1);
	tmp = 0;
	if (flags.check_flags & 0x04 && flags.precision > l)
		tmp = flags.precision - l + 2;
	if (flags.check_char & 0x01)
		ft_putchar_count("0x", 2);
	if (flags.check_flags & 0x08 && flags.width > l && !(flags.check_char & 4))
		print_width_p(tmp, flags, l);
	if (!(flags.check_char & 0x01))
		ft_putchar_count("0x", 2);
	if (l == 1 && (unsigned long)element == 0)
		l--;
	if (flags.check_flags & 0x04 && flags.precision > l)
		while (flags.precision-- > l)
			ft_putchar_count("0", 1);
	l = 1;
	if (!((unsigned long)element == 0 && flags.check_flags & 0x04))
		ft_putlnbr_base((unsigned long)element, 16, 0, &l);
	if (flags.check_flags & 0x08 && flags.width > l && (flags.check_char & 04))
		print_width_p(tmp, flags, l);
}
