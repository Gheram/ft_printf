/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:32:20 by ghtouman          #+#    #+#             */
/*   Updated: 2018/12/04 18:12:49 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

int g_ret;

typedef	struct		s_flags
{
	char			check_flags;
	unsigned char	index_s;
	int				index_m;
	unsigned int	precision;
	unsigned int	width;
	char			w;
	char			check_char;
}					t_flags;

typedef struct		s_specifier
{
	char			flag_s;
	void			(*fct_s)(void*, t_flags);
}					t_specifier;

typedef struct		s_modifier
{
	char			flag_m;
	void			(*fct_m)(void*, t_flags);
}					t_modifier;

typedef struct		s_character
{
	char			flag_c;
	void			(*fct_c)(void*, t_flags*);
}					t_character;

int					ft_printf(const char *format, ...);
void				print_d_i(void *element, t_flags flags);
void				print_o(void *element, t_flags flags);
void				print_lo(void *element, t_flags flags);
void				print_x(void *element, t_flags flags);
void				print_xx(void *element, t_flags flags);
void				print_u(void *element, t_flags flags);
void				print_lu(void *element, t_flags flags);
void				print_ld(void *element, t_flags flags);
void				print_p(void *element, t_flags flags);
void				print_c(void *element, t_flags flags);
void				print_lc(void *element, t_flags flags);
void				print_s(void *element, t_flags flags);
void				print_ls(void *element, t_flags flags);
void				print_percent(void *element, t_flags flags);

void				print_f(double element, t_flags flags);
void				print_lf(long double element, t_flags flags);
void				ft_putfloat(double f, size_t *len, unsigned int p);
void				ft_putlfloat(long double f, size_t *len, unsigned int p);

void				modif_h(void *element, t_flags flags);
void				modif_hh(void *element, t_flags flags);
void				modif_j(void *element, t_flags flags);
void				modif_l(void *element, t_flags flags);
void				modif_ll(void *element, t_flags flags);
void				modif_z(void *element, t_flags flags);

void				ft_control(t_flags flags, va_list ap);
void				ft_putnbr_base
					(unsigned int n, unsigned int b, char maj, size_t *len);
void				ft_putlnbr_base
					(unsigned long n, unsigned int b, char maj, size_t *len);
void				ft_putllnbr_base
					(uintmax_t n, uintmax_t b, char maj, size_t *len);
void				ft_putlnbr(long int n, size_t *len);
void				ft_putnbr_no_minus(intmax_t n, size_t *len);

void				ft_putwchar(wchar_t element);
void				ft_putchar_count(char *c, size_t len);
void				ft_putchar_one(char c);
void				ft_putchar_null(t_flags flags);
void				ft_putwstr(wchar_t *str);
int					ft_str_unicode_error(wchar_t *str, int p);
int					ft_unicode_error(wchar_t str);

size_t				ft_len_number(intmax_t nb, size_t len, char base);
size_t				ft_len_number_u(uintmax_t nb, size_t len, char base);
size_t				ft_weight_wchar(wchar_t c);
size_t				ft_strlen(const char *str);

int					ft_parse_flags(const char *format, va_list ap, int num_var);
void				ft_check_characters(t_flags *flags, char **str);
void				ft_check_modifier(t_flags *flags, char **str);
void				ft_check_precision(t_flags *flags, char **str);
int					ft_write_p_u(uintmax_t element, t_flags flags, char base);
int					ft_write_p(intmax_t element, t_flags flags, char base);

int					ft_check_specifier(t_flags *flags, char *str);

void				ft_check_width(t_flags *flags, char **str);
void				ft_print_width(intmax_t element, t_flags flags, int len);
int					ft_print_width_u(uintmax_t elem, t_flags flags, int len);
void				ft_print_width_s(t_flags flags, size_t len);
void				ft_back_w(intmax_t element, t_flags flags, size_t len);

void				ft_width_unicode(t_flags flags, wchar_t *str);

void				charac_plus_sign(void *element, t_flags *flags);
void				charac_sp(void *element, t_flags *flags);
void				charac_sharp(void *element, t_flags *flags);
void				charac_zero(void *element, t_flags *flags);
void				charac_minus(void *element, t_flags *flags);
int					ft_found_unicode
					(va_list ap, const char *fornat, int *num_var);

#endif
