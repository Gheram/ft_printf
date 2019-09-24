/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charac_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:20:15 by tigre             #+#    #+#             */
/*   Updated: 2018/11/29 22:14:58 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	charac_plus_sign(void *element, t_flags *flags)
{
	if (flags->index_s < 2 && (int)element >= 0)
		ft_putchar_count("+", 1);
	if (flags->index_s == 2 && (long int)element >= 0)
		ft_putchar_count("+", 1);
}

void	charac_sp(void *element, t_flags *flags)
{
	if ((flags->index_s < 2 || flags->index_s == 20)
	&& (int)element >= 0 && !(flags->check_char & 0x08))
	{
		ft_putchar_count(" ", 1);
		if (flags->width > 0)
			flags->width--;
	}
	if (flags->index_s == 2 && (long int)element >= 0 &&
	!(flags->check_char & 0x08))
	{
		ft_putchar_count(" ", 1);
		if (flags->width > 0)
			flags->width--;
	}
}

void	charac_sharp(void *element, t_flags *flags)
{
	if (flags->index_s == 3 && (unsigned int)element == 0)
		ft_putchar_count("0", 1);
	if (flags->index_s == 3 && (unsigned int)element > 0)
		ft_putchar_count("0", 1);
	if (flags->index_s == 4 && (unsigned long int)element == 0)
		ft_putchar_count("0", 1);
	if (flags->index_s == 4 && (unsigned long int)element > 0)
		ft_putchar_count("0", 1);
	if (flags->index_s == 7 && (unsigned int)element > 0)
		ft_putchar_count("0x", 2);
	if (flags->index_s == 8 && (unsigned int)element > 0)
		ft_putchar_count("0X", 2);
}

void	charac_minus(void *element, t_flags *flags)
{
	(void)element;
	(void)flags;
}

void	charac_zero(void *element, t_flags *flags)
{
	(void)element;
	if (flags->check_flags & 0x04 && flags->index_s < 10)
		return ;
	if (flags->check_char & 0x04)
		return ;
	if (flags->check_char & 0x01)
		flags->w = '0';
}
