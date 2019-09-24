/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:30:21 by ghtouman          #+#    #+#             */
/*   Updated: 2018/12/04 19:16:46 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] > 0x7f && str[i] <= 0xff && MB_CUR_MAX != 4)
				ft_putchar_one(str[i]);
			else
				ft_putwchar(str[i]);
			i++;
		}
	}
}
