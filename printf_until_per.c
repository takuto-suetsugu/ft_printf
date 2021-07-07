/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_until_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:33:17 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 23:09:41 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_until_per(char **process_start_point)
{
	int	len_until_per;

	len_until_per = 0;
	while (**process_start_point && **process_start_point != '%')
	{
		write(1, *process_start_point, 1);
		(*process_start_point)++;
		len_until_per++;
	}
	return (len_until_per);
}
