/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:23:36 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/29 20:03:51 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAG_H
# define FT_FLAG_H

static t_specifier g_specifier[] =
{
	{'d', &print_d_i},
	{'i', &print_d_i},
	{'D', &print_ld},
	{'o', &print_o},
	{'O', &print_lo},
	{'u', &print_u},
	{'U', &print_lu},
	{'x', &print_x},
	{'X', &print_xx},
	{'p', &print_p},
	{'c', &print_c},
	{'C', &print_lc},
	{'s', &print_s},
	{'S', &print_ls},
	{'%', &print_percent},
	{'\0', NULL}
};

static t_modifier g_modifier[] =
{
	{'h', &modif_h},
	{'l', &modif_l},
	{'j', &modif_j},
	{'z', &modif_z},
	{'H', &modif_hh},
	{'L', &modif_ll},
	{'\0', NULL}
};

static t_character g_character[] =
{
	{'0', &charac_zero},
	{'#', &charac_sharp},
	{'-', &charac_minus},
	{'+', &charac_plus_sign},
	{' ', &charac_sp},
	{'\0', NULL}
};

#endif
