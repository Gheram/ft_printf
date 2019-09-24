/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:31:51 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/29 20:13:04 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

int		ft_check_specifier(t_flags *flags, char *str)
{
	flags->index_s = 0;
	while (g_specifier[flags->index_s].flag_s &&
		*str != g_specifier[flags->index_s].flag_s)
		flags->index_s++;
	if (*str == 'f')
	{
		flags->check_flags = flags->check_flags + 0x01;
		return (flags->index_s = 20);
	}
	if (flags->index_s < 14)
		flags->check_flags = flags->check_flags + 0x01;
	return (flags->index_s);
}
