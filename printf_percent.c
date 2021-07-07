/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:27:38 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 19:47:37 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_percent_putchar(t_command *cmd, t_len_for_command *print_len)
{
	if (cmd->flag[0] == '-' || cmd->flag[1] == '-')
	{
		ft_putchar_byte('0', (print_len -> precision));
		write(1, "%", print_len -> type);
		ft_putchar_byte(' ', (print_len -> width));
	}
	else if (cmd->flag[0] == '0' && cmd->flag[1] != '-' && cmd->precision < 0)
	{
		ft_putchar_byte('0', (print_len -> width));
		ft_putchar_byte('0', (print_len -> precision));
		write(1, "%", print_len -> type);
	}
	else
	{
		ft_putchar_byte(' ', (print_len -> width));
		ft_putchar_byte('0', (print_len -> precision));
		write(1, "%", print_len -> type);
	}
}

int	printf_percent(t_command *cmd)
{
	t_len_for_command	print_len;

	set_up_print_len(&print_len);
	print_len.type = 1;
	if (cmd->precision == 0)
	{
		print_len.width = cmd->width;
		update_if_under_0(&print_len);
		ft_putchar_byte(' ', print_len.width);
		return (print_len.width);
	}
	print_len.precision = cmd->precision - print_len.type;
	if (cmd->precision > print_len.type)
		print_len.width = cmd->width - cmd->precision;
	else
		print_len.width = cmd->width - print_len.type;
	update_if_under_0(&print_len);
	ft_percent_putchar(cmd, &print_len);
	return (print_len.type + print_len.precision + print_len.width);
}
