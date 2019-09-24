/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_h_hh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:02:44 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/28 15:20:32 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		modif_h(void *element, t_flags flags)
{
	size_t len;

	len = 1;
	if (flags.index_s == 3)
	{
		if ((unsigned short int)element == 0 && flags.precision == 0 &&
		flags.check_char & 0x02)
			ft_putchar_one('0');
		else if (ft_write_p_u((unsigned short int)element, flags, 8))
			ft_putnbr_base((unsigned short int)element, 8, 0, &len);
	}
	if (flags.index_s == 5)
		if (ft_write_p_u((unsigned short int)element, flags, 10))
			ft_putnbr_base((unsigned short int)element, 10, 0, &len);
	if (flags.index_s == 7)
		if (ft_write_p_u((unsigned short int)element, flags, 16))
			ft_putnbr_base((unsigned short int)element, 16, 0, &len);
	if (flags.index_s == 8)
		if (ft_write_p_u((unsigned short int)element, flags, 16))
			ft_putnbr_base((unsigned short int)element, 16, 1, &len);
	if (flags.index_s < 3)
		if (ft_write_p((short int)element, flags, 10))
			ft_putnbr_no_minus((short int)element, &len);
	if (flags.check_char & 0x04)
		ft_back_w((short int)element, flags, len);
}

void		modif_hh(void *element, t_flags flags)
{
	size_t len;

	len = 1;
	if (flags.index_s == 3)
	{
		if ((unsigned char)element == 0 && flags.precision == 0 &&
		flags.check_char & 0x02)
			ft_putchar_one('0');
		else if (ft_write_p_u((unsigned char)element, flags, 8))
			ft_putnbr_base((unsigned char)element, 8, 0, &len);
	}
	if (flags.index_s == 5)
		if (ft_write_p_u((unsigned char)element, flags, 10))
			ft_putnbr_base((unsigned char)element, 10, 0, &len);
	if (flags.index_s == 7)
		if (ft_write_p_u((unsigned char)element, flags, 16))
			ft_putnbr_base((unsigned char)element, 16, 0, &len);
	if (flags.index_s == 8)
		if (ft_write_p_u((unsigned char)element, flags, 16))
			ft_putnbr_base((unsigned char)element, 16, 1, &len);
	if (flags.index_s < 3)
		if (ft_write_p((char)element, flags, 10))
			ft_putnbr_no_minus((char)element, &len);
	if (flags.check_char & 0x04)
		ft_back_w((char)element, flags, len);
}
