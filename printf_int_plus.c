/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:24:37 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 17:28:25 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_int_plus(t_command *cmd,
		t_len_for_command *print_len, char *str_arg)
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
