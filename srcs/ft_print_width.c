/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:28:31 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/28 15:19:57 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_back_w(intmax_t element, t_flags flags, size_t len)
{
	long int tmp;
	long int diff;

	diff = 0;
	if (flags.precision > (unsigned int)len)
		diff = (long int)flags.precision - len;
	tmp = (long int)flags.width - len - diff;
	if (element > 0 && flags.check_char & 0x08 && flags.check_char & 0x04 &&
	flags.index_s < 3)
		tmp--;
	if ((flags.index_s == 3 || flags.index_s == 4) && flags.check_char & 0x02)
		tmp--;
	if ((flags.index_s == 7 || flags.index_s == 8) && flags.check_char & 0x02)
		tmp -= 2;
	if (flags.precision > 0 && flags.check_char & 0x02 && element == 0)
		tmp++;
	while (tmp > 0)
	{
		ft_putchar_count(&flags.w, 1);
		tmp--;
	}
}
