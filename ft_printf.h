/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:35:16 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/08 14:51:16 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
typedef struct s_command
{
	int	flag[2];
	int	width;
	int	precision;
	int	modifier;
	int	type;
}				t_command;

typedef struct s_len_for_command
{
	int	type;
	int	width;
	int	precision;
}				t_len_for_command;

int		ft_printf(const char *fmt, ...);
int		printf_until_per(char **process_start_point);
char	*go_until_cmd_end(char *cmd_end_p);
int		begin_cmd_proc(char *str_on_cmd, va_list args);
char	*save_cmd_to_structure(t_command *cmd, char *str_on_cmd, va_list args);
int		printf_int(t_command *cmd, va_list args);
int		printf_char(t_command *cmd, va_list args);
int		printf_str(t_command *cmd, va_list args);
int		printf_u(t_command *cmd, va_list args);
int		printf_x(t_command *cmd, va_list args);
int		printf_large_X(t_command *cmd, va_list args);
int		count_flag(char *str);
int		count_width(char *str);
int		count_precision(char *str);
int		count_type(char *str);
void	set_up_print_len(t_len_for_command *print_len);
void	update_if_under_0(t_len_for_command *print_len);
void	ft_putchar_byte(char c, int byte);
char	*ft_itoa(int n, t_len_for_command *cmd_len);
void	printf_int_plus(t_command *cmd, t_len_for_command
			*print_len, char *str_arg);
void	printf_int_minus(t_command *cmd,
			t_len_for_command *print_len, char *str_arg);
int		ft_strlen(const char *str);
char	*ft_unsigned_into_str(unsigned int n, t_len_for_command *cmd_len);
char	*ft_10_into_16(long x_arg, t_len_for_command *print_len);
char	*ft_large_10_into_16(unsigned int x_arg, t_len_for_command *print_len);
int		printf_percent(t_command *cmd);
int		printf_pointer(t_command *cmd, va_list args);

#endif
