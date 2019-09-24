/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:19:53 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/29 14:47:03 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

void		print_d_i(void *element, t_flags flags)
{
	size_t	len;

	len = 1;
	if (flags.check_flags & 0x02)
	{
		g_modifier[flags.index_m].fct_m(element, flags);
		return ;
	}
	if (ft_write_p((int)element, flags, 10))
		ft_putnbr_no_minus((int)element, &len);
	if (flags.check_char & 0x04)
		ft_back_w((int)element, flags, len);
}

void		print_ld(void *element, t_flags flags)
{
	size_t	len;

	len = 1;
	if (ft_write_p((long int)element, flags, 10))
		ft_putlnbr((long int)element, &len);
	if (flags.check_char & 0x04)
		ft_back_w((long int)element, flags, len);
}
