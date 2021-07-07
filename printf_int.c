/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:40:47 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/08 09:40:30 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_int_minus_putchar(t_command *cmd, long i_arg,
		t_len_for_command print_len)
{
	char				*str_arg;

	str_arg = ft_itoa(i_arg, &print_len);
	str_arg++;
	print_len.type--;
	print_len.precision = cmd->precision - print_len.type;
	if (cmd->precision > print_len.type)
		print_len.width = cmd->width - (cmd->precision + 1);
	else
		print_len.width = cmd->width - (print_len.type + 1);
	update_if_under_0(&print_len);
	printf_int_minus(cmd, &print_len, str_arg);
	free (str_arg - 1);
	return (1 + print_len.type + print_len.precision + print_len.width);
}

long	ft_int_plus_putchar(t_command *cmd, long i_arg,
		t_len_for_command print_len)
{
	char				*str_arg;

	str_arg = ft_itoa(i_arg, &print_len);
	print_len.precision = cmd->precision - print_len.type;
	if (cmd->precision > print_len.type)
		print_len.width = cmd->width - cmd->precision;
	else
		print_len.width = cmd->width - print_len.type;
	update_if_under_0(&print_len);
	printf_int_plus(cmd, &print_len, str_arg);
	free (str_arg);
	return (print_len.type + print_len.precision + print_len.width);
}

int	printf_int(t_command *cmd, va_list args)
{
	long				i_arg;
	t_len_for_command	print_len;
	long				return_value;

	return_value = 0;
	set_up_print_len(&print_len);
	i_arg = (int)va_arg(args, int);
	if (i_arg == 0 && cmd->precision == 0)
	{
		print_len.width = cmd->width;
		update_if_under_0(&print_len);
		ft_putchar_byte(' ', print_len.width);
		return (print_len.width);
	}
	if (i_arg < 0)
		return_value = ft_int_minus_putchar(cmd, i_arg, print_len);
	else if (i_arg >= 0)
		return_value = ft_int_plus_putchar(cmd, i_arg, print_len);
	return (return_value);
}
