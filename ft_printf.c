/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:18:37 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/08 12:42:02 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy_s1;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	cpy_s1 = malloc(sizeof(char) * s1_len + 1);
	if (cpy_s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy_s1[i] = s1[i];
		i++;
	}
	cpy_s1[i] = '\0';
	return (cpy_s1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		total_outputted_len;
	char	*process_start_point;
	char	*start;

	va_start(args, fmt);
	total_outputted_len = 0;
	if (fmt == NULL)
		return (-1);
	process_start_point = ft_strdup(fmt);
	start = process_start_point;
	while (*process_start_point != '\0')
	{
		if (*process_start_point != '%')
			total_outputted_len += printf_until_per(&process_start_point);
		if (*process_start_point == '%')
		{
			total_outputted_len += begin_cmd_proc(process_start_point, args);
			process_start_point = go_until_cmd_end(process_start_point);
		}
	}
	va_end(args);
	free(start);
	return (total_outputted_len);
}
