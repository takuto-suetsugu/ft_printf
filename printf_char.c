/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:52:30 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 19:47:17 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_char(t_command *cmd, va_list args)
{
	unsigned char		c_arg;
	t_len_for_command	print_len;

	c_arg = (unsigned char)va_arg(args, int);
	set_up_print_len(&print_len);
	print_len.type = 1;
	if (cmd->precision > print_len.type)
		print_len.width = cmd->width - cmd->precision;
	else
		print_len.width = cmd->width - print_len.type;
	update_if_under_0(&print_len);
	if (cmd->flag[0] == '-' || cmd->flag[1] == '-')
	{
		write(1, &c_arg, print_len.type);
		ft_putchar_byte(' ', (print_len.width));
	}
	else
	{
		ft_putchar_byte(' ', (print_len.width));
		write(1, &c_arg, print_len.type);
	}
	return (print_len.type + print_len.width);
}
