# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigre <tigre@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 00:36:32 by tigre             #+#    #+#              #
#    Updated: 2018/11/30 11:59:44 by ghtouman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c			\
	  ft_parse_flags.c		\
	  ft_check_characters.c	\
	  ft_check_width.c		\
	  ft_check_precision.c	\
	  ft_check_modifier.c	\
	  ft_check_specifier.c	\
	  ft_control.c			\
	  ft_print_int.c		\
	  ft_print_long.c		\
	  ft_print_p.c			\
	  ft_float.c			\
	  ft_print_float.c		\
	  ft_print_unsigned_int.c\
	  modif_h_hh.c			\
	  modif_l_ll.c			\
	  modif_j_z.c			\
	  ft_putnbr_all.c		\
	  ft_len_number.c		\
	  ft_print_char.c		\
	  ft_putwchar.c			\
	  ft_putwstr.c			\
	  ft_charac_handler.c	\
	  ft_weight_wchar.c		\
	  ft_print_width.c		\
	  ft_error_unicode.c	\
	  ft_print_unicode.c

SRCS_PATH = $(addprefix srcs/, $(SRCS))

OBJ = $(SRCS_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -Ofast -c $< -I ./includes/ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
