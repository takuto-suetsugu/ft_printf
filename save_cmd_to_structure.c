/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cmd_to_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:42:33 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 15:50:33 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_save_flag(t_command *cmd, char *str)
{
	cmd->flag[0] = *str;
	if (count_flag(str) == 1)
		str++;
	else if (count_flag(str) >= 2)
	{
		while (*str == '0' || *str == '-')
		{
			if (*str != cmd->flag[0])
				cmd->flag[1] = *str;
			str++;
		}
	}
	return (str);
}

char	*ft_save_width(t_command *cmd, char *str, va_list args)
{
	int	digit_width;

	digit_width = 0;
	if (*str == '*')
	{
		cmd->width = (int)va_arg(args, int);
		if (cmd->width < 0)
		{
			cmd->width *= -1;
			cmd->flag[0] = '-';
		}
		str++;
	}
	else
	{
		cmd->width = 0;
		digit_width = count_width(str);
		while (digit_width > 0)
		{
			cmd->width = cmd->width * 10 + (*str - '0');
			str++;
			digit_width--;
		}
	}
	return (str);
}

char	*ft_save_precision(t_command *cmd, char *str, va_list args)
{
	int	digit_pre;

	digit_pre = 0;
	if (*(str + 1) == '*')
	{
		cmd->precision = (int)va_arg(args, int);
		if (cmd->precision < 0)
			cmd->precision = -1;
		str += 2;
	}
	else
	{
		digit_pre = count_precision(str) - 1;
		str++;
		cmd->precision = 0;
		while (digit_pre > 0)
		{
			cmd->precision = cmd->precision * 10 + (*str - '0');
			str++;
			digit_pre--;
		}
	}
	return (str);
}

char	*save_cmd_to_structure(t_command *cmd, char *str_on_cmd, va_list args)
{
	if (count_flag(str_on_cmd) >= 1)
		str_on_cmd = ft_save_flag(cmd, str_on_cmd);
	if (count_width(str_on_cmd) >= 1)
		str_on_cmd = ft_save_width(cmd, str_on_cmd, args);
	if (count_precision(str_on_cmd) == 1)
	{
		cmd->precision = 0;
		str_on_cmd++;
	}
	else if (count_precision(str_on_cmd) >= 2)
		str_on_cmd = ft_save_precision(cmd, str_on_cmd, args);
	if (count_type(str_on_cmd) == 1)
	{
		cmd->type = *str_on_cmd;
		str_on_cmd++;
	}
	return (str_on_cmd);
}
