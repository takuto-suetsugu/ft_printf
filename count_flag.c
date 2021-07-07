/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:44:45 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 23:23:24 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_flag(char *str)
{
	int	count;

	count = 0;
	while (*str == '0' || *str == '-')
	{
		count++;
		str++;
	}
	return (count);
}
