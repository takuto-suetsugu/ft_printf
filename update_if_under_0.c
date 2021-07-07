/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_if_under_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:03:39 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/06 16:08:17 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	update_if_under_0(t_len_for_command *print_len)
{
	if (print_len->type < 0)
		print_len->type = 0;
	if (print_len->precision < 0)
		print_len->precision = 0;
	if (print_len->width < 0)
		print_len->width = 0;
}
