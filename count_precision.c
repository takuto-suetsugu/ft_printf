/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:46:28 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/06 15:21:00 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_precision(char *str)
{
	int	len;

	len = 0;
	if (*str && *str == '.')
	{
		len++;
		str++;
		if (*str && (*str == '*'))
			return (2);
		if (*str && *str == '-')
			len++;
		while (*str && ('0' <= *str && *str <= '9'))
		{
			str++;
			len++;
		}
	}
	return (len);
}
