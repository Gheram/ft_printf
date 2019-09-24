/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:22:02 by ghtouman          #+#    #+#             */
/*   Updated: 2018/10/31 15:06:32 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_len_number(intmax_t nb, size_t len, char base)
{
	if (nb < 0 && base == 10)
	{
		nb = -nb;
		len++;
	}
	if (nb == 0 && len == 0)
		return (1);
	else if (nb == 0)
		return (len);
	return (ft_len_number(nb / base, len + 1, base));
}

size_t	ft_len_number_u(uintmax_t nb, size_t len, char base)
{
	if (nb == 0 && len == 0)
		return (1);
	else if (nb == 0)
		return (len);
	return (ft_len_number(nb / base, len + 1, base));
}
