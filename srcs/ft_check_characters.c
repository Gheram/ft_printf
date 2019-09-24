/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:32:11 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/28 20:37:23 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

int		index_byte(int nb)
{
	if (nb == 0)
		return (1);
	if (nb > 0)
		return ((index_byte(nb - 1)) * 2);
	else
		return (0);
}

void	ft_check_characters(t_flags *flags, char **str)
{
	int		i;

	i = 0;
	while (g_character[i].flag_c)
	{
		if (g_character[i].flag_c == **str)
		{
			flags->check_char |= index_byte(i);
			i = 0;
			(*str)++;
			flags->check_flags |= 0x10;
		}
		else
			i++;
	}
}
