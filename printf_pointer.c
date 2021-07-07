/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:08:23 by tsuetsug          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/08 14:36:44 by tsuetsug         ###   ########.fr       */
=======
/*   Updated: 2021/05/08 14:37:47 by tsuetsug         ###   ########.fr       */
>>>>>>> 7cc1b3e4090bb0883afbb971e16472fbad4a7179
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_putchar(t_command *cmd,
		t_len_for_command *print_len, char *str_arg)
{
	if (cmd->flag[0] == '-' || cmd->flag[1] == '-')
	{
		write(1, "0x", 2);
		ft_putchar_byte('0', (print_len -> precision));
		write(1, str_arg, print_len -> type);
		ft_putchar_byte(' ', (print_len -> width));
	}
	else if (cmd->flag[0] == '0' && cmd->flag[1] != '-' && cmd->precision < 0)
	{
		ft_putchar_byte('0', (print_len -> width));
		write(1, "0x", 2);
		ft_putchar_byte('0', (print_len -> precision));
		write(1, str_arg, print_len -> type);
	}
	else
	{
		ft_putchar_byte(' ', (print_len -> width));
		write(1, "0x", 2);
		ft_putchar_byte('0', (print_len -> precision));
		write(1, str_arg, print_len -> type);
	}
}

int	printf_pointer(t_command *cmd, va_list args)
{
	void				*arg;
	char				*str_arg;
	long				address_str_arg;
	t_len_for_command	print_len;

	arg = (void *)va_arg(args, void *);
	address_str_arg = (long)arg;
	set_up_print_len(&print_len);
	if (arg == NULL)
	{
		str_arg = (char *)malloc(2);
		*str_arg = '0';
		print_len.type++;
	}
	else
		str_arg = ft_10_into_16(address_str_arg, &print_len);
	if (cmd->precision == 0)
		print_len.type = 0;
	print_len.precision = cmd->precision - print_len.type;
	print_len.width = cmd->width - (2 + print_len.type);
	update_if_under_0(&print_len);
	ft_pointer_putchar(cmd, &print_len, str_arg);
	free(str_arg);
	return (2 + print_len.type + print_len.precision + print_len.width);
}
