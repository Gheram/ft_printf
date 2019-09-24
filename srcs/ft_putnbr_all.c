/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:22:02 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/30 14:23:01 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int n, unsigned int b, char maj, size_t *len)
{
	if (n >= b)
	{
		(*len)++;
		ft_putnbr_base(n / b, b, maj, len);
	}
	if (n % b < 10)
		ft_putchar_one(n % b + '0');
	else if (maj == 1)
		ft_putchar_one(n % b + 'A' - 10);
	else
		ft_putchar_one(n % b + 'a' - 10);
}

void	ft_putlnbr_base(unsigned long n, unsigned int b, char maj, size_t *len)
{
	if (n >= b)
	{
		(*len)++;
		ft_putlnbr_base(n / b, b, maj, len);
	}
	if (n % b < 10)
		ft_putchar_one(n % b + '0');
	else if (maj == 1)
		ft_putchar_one(n % b + 'A' - 10);
	else
		ft_putchar_one(n % b + 'a' - 10);
}

void	ft_putllnbr_base(uintmax_t n, uintmax_t b, char maj, size_t *len)
{
	if (n >= b)
	{
		(*len)++;
		ft_putllnbr_base(n / b, b, maj, len);
	}
	if (n % b < 10)
		ft_putchar_one(n % b + '0');
	else if (maj == 1)
		ft_putchar_one(n % b + 'A' - 10);
	else
		ft_putchar_one(n % b + 'a' - 10);
}

void	ft_putlnbr(long int n, size_t *len)
{
	if (n < -9223372036854775807)
		return (ft_putchar_count("9223372036854775808", 19));
	if (n < 0)
	{
		n = -n;
		(*len)++;
	}
	if (n >= 10)
	{
		(*len)++;
		ft_putlnbr(n / 10, len);
	}
	ft_putchar_one(n % 10 + '0');
}

void	ft_putnbr_no_minus(intmax_t n, size_t *len)
{
	if (n < -9223372036854775807)
		return (ft_putchar_count("9223372036854775808", 19));
	if (n < 0)
	{
		n = -n;
		(*len)++;
	}
	if (n >= 10)
	{
		(*len)++;
		ft_putnbr_no_minus(n / 10, len);
	}
	ft_putchar_one((n % 10) + '0');
}
