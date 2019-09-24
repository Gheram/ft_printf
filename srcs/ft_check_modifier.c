/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:32:06 by ghtouman          #+#    #+#             */
/*   Updated: 2018/12/04 18:12:14 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

static int		hh_and_ll(char **str, t_flags *flags, int tmp)
{
	if (tmp == 0 && *((*str) + 1) && *((*str) + 1) == 'h')
	{
		flags->index_m == -1 ? flags->index_m = 4 : flags->index_m;
		flags->check_flags |= 0x02;
		(*str) += 2;
		return (1);
	}
	else if (tmp == 1 && *((*str) + 1) && *((*str) + 1) == 'l')
	{
		flags->index_m = 5;
		flags->check_flags |= 0x02;
		(*str) += 2;
		return (1);
	}
	return (0);
}

void			ft_check_modifier(t_flags *flags, char **str)
{
	int			tmp;

	tmp = 0;
	while (g_modifier[tmp].flag_m && **str != g_modifier[tmp].flag_m)
		tmp++;
	if (hh_and_ll(str, flags, tmp))
		return ;
	else if (tmp < 4)
	{
		flags->index_m < tmp ? flags->index_m = tmp : flags->index_m;
		if (flags->index_m == 4)
			flags->index_m = tmp;
		flags->check_flags |= 0x02;
		(*str)++;
	}
	else if (tmp == 5)
	{
		flags->index_m = 5;
		flags->check_flags |= 0x02;
		flags->check_flags |= 0x20;
		(*str) += 1;
	}
}
