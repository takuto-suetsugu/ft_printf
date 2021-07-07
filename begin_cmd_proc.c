/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_cmd_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:40:04 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 23:35:48 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_up_cmd(t_command *s)
{
	s->flag[0] = 0;
	s->flag[1] = 0;
	s->width = -1;
	s->precision = -1;
	s->type = -1;
}

int	begin_cmd_proc(char *str_on_cmd, va_list args)
{
	int			outputted_len_on_cmd;
	t_command	cmd;

	outputted_len_on_cmd = 0;
	set_up_cmd(&cmd);
	str_on_cmd++;
	str_on_cmd = save_cmd_to_structure(&cmd, str_on_cmd, args);
	if (cmd.type == 'd' || cmd.type == 'i')
		outputted_len_on_cmd = printf_int(&cmd, args);
	else if (cmd.type == 'c')
		outputted_len_on_cmd = printf_char(&cmd, args);
	else if (cmd.type == 's')
		outputted_len_on_cmd = printf_str(&cmd, args);
	else if (cmd.type == 'u')
		outputted_len_on_cmd = printf_u(&cmd, args);
	else if (cmd.type == 'x')
		outputted_len_on_cmd = printf_x(&cmd, args);
	else if (cmd.type == 'X')
		outputted_len_on_cmd = printf_large_X(&cmd, args);
	else if (cmd.type == 'p')
		outputted_len_on_cmd = printf_pointer(&cmd, args);
	else if (cmd.type == '%')
		outputted_len_on_cmd = printf_percent(&cmd);
	return (outputted_len_on_cmd);
}
