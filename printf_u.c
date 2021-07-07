/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:05:51 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/08 09:41:21 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_putchar(t_command *cmd, t_len_for_command *print_len,
		const char *str_arg)
{
	if (cmd->flag[0] == '-' || cmd->flag[1] == '-')
	{
		ft_putchar_byte('0', (print_len->precision));
		write(1, str_arg, print_len->type);
		ft_putchar_byte(' ', (print_len->width));
	}
	else if (cmd->flag[0] == '0' && cmd->flag[1] != '-' && cmd->precision < 0)
	{
		ft_putchar_byte('0', (print_len->width));
		ft_putchar_byte('0', (print_len->precision));
		write(1, str_arg, print_len->type);
	}
	else
	{
		ft_putchar_byte(' ', (print_len->width));
		ft_putchar_byte('0', (print_len->precision));
		write(1, str_arg, print_len->type);
	}
}

int	printf_u(t_command *cmd, va_list args)
{
	unsigned int		u_arg;
	char				*str_arg;
	t_len_for_command	print_len;

	set_up_print_len(&print_len);
	u_arg = (unsigned int)va_arg(args, unsigned int);
	if (u_arg == 0 && cmd->precision == 0)
	{
		print_len.width = cmd->width;
		update_if_under_0(&print_len);
		ft_putchar_byte(' ', print_len.width);
		return (print_len.width);
	}
	str_arg = ft_unsigned_into_str(u_arg, &print_len);
	print_len.precision = cmd->precision - print_len.type;
	if (cmd -> precision > print_len.type)
		print_len.width = cmd -> width - cmd-> precision;
	else
		print_len.width = cmd -> width - print_len.type;
	update_if_under_0(&print_len);
	ft_u_putchar(cmd, &print_len, str_arg);
	free (str_arg);
	return (print_len.type + print_len.precision + print_len.width);
}
