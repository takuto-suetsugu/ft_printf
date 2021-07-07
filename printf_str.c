/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:20:42 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/06 22:40:07 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_proc(t_command *cmd,
		t_len_for_command *print_len, const char *s_arg)
{
	if (cmd->flag[0] == '-' || cmd->flag[1] == '-')
	{
		write(1, s_arg, print_len -> type);
		ft_putchar_byte(' ', (print_len -> width));
	}
	else if (cmd->flag[0] == '0' && cmd->flag[1] != '-')
	{
		ft_putchar_byte('0', (print_len -> width));
		write(1, s_arg, print_len -> type);
	}
	else
	{
		ft_putchar_byte(' ', (print_len -> width));
		write(1, s_arg, print_len -> type);
	}
}

int	printf_str(t_command *cmd, va_list args)
{
	const char			*s_arg;
	t_len_for_command	print_len;

	s_arg = (char *)va_arg(args, char *);
	if (s_arg == NULL)
		s_arg = "(null)";
	set_up_print_len(&print_len);
	print_len.type = ft_strlen(s_arg);
	if (cmd->precision != -1 && cmd->precision < print_len.type)
		print_len.type = cmd->precision;
	print_len.width = cmd->width - print_len.type;
	update_if_under_0(&print_len);
	ft_str_proc(cmd, &print_len, s_arg);
	return (print_len.type + print_len.width);
}
