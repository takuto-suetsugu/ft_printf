/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_print_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:02:37 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/06 21:42:13 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_up_print_len(t_len_for_command *print_len)
{
	print_len->type = 0;
	print_len->precision = 0;
	print_len->width = 0;
}
