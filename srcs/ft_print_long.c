/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:20:00 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/28 15:25:35 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

void		print_lu(void *element, t_flags flags)
{
	size_t	len;

	len = 1;
	if (ft_write_p_u((unsigned long)element, flags, 10))
		ft_putlnbr_base((unsigned long)element, 10, 0, &len);
	if (flags.check_char & 0x04)
		ft_back_w((unsigned long)element, flags, len);
}

void		print_lo(void *element, t_flags flags)
{
	size_t	len;

	len = 1;
	if (flags.check_char & 0x02 && (unsigned long)element == 0 &&
	flags.precision < 2)
	{
		ft_print_width_u((unsigned long)element, flags, len);
		ft_putchar_one('0');
	}
	else if (ft_write_p_u((unsigned long)element, flags, 8))
		ft_putlnbr_base((unsigned long)element, 8, 0, &len);
	if (flags.check_char & 0x04)
		ft_back_w((unsigned long)element, flags, len);
}
