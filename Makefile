# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 18:05:22 by tsuetsug          #+#    #+#              #
#    Updated: 2021/05/08 14:51:24 by tsuetsug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			= ft_printf.c ft_itoa.c printf_until_per.c \
			begin_cmd_proc.c printf_int.c save_cmd_to_structure.c \
			go_until_cmd_end.c count_flag.c count_width.c count_precision.c \
			count_type.c ft_putchar_byte.c printf_int_plus.c printf_int_minus.c \
			printf_char.c set_up_print_len.c update_if_under_0.c printf_str.c \
			ft_strlen.c  printf_percent.c printf_u.c printf_pointer.c \
			ft_unsigned_into_str.c ft_10_into_16.c printf_x.c printf_large_X.c \
			ft_large_10_into_16.c main.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I.
RM				= rm -f

all:			$(NAME)

$(NAME):
				CC $(CFLAGS) -c $(SRCS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

clean:
				$(RM) $(OBJS)
fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)