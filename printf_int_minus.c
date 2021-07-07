/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:19:45 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 19:19:26 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_int_minus(t_command *cmd, t_len_for_command *print_len,
		char *str_arg)
{
	if (cmd->flag[0] == '-' || cmd->flag[1] == '-')
	{
		write(1, "-", 1);
		ft_putchar_byte('0', (print_len->precision));
		write(1, str_arg, print_len->type);
		ft_putchar_byte(' ', (print_len->width));
	}
	else if (cmd->flag[0] == '0' && cmd->flag[1] != '-' && cmd->precision < 0)
	{
		write(1, "-", 1);
		ft_putchar_byte('0', (print_len->width));
		ft_putchar_byte('0', (print_len->precision));
		write(1, str_arg, print_len->type);
	}
	else
	{
		ft_putchar_byte(' ', (print_len->width));
		write(1, "-", 1);
		ft_putchar_byte('0', (print_len->precision));
		write(1, str_arg, print_len->type);
	}
}
