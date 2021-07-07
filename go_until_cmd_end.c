/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_until_cmd_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:43:53 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/06 15:52:19 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*go_until_cmd_end(char *cmd_end_p)
{
	cmd_end_p++;
	cmd_end_p += count_flag(cmd_end_p);
	cmd_end_p += count_width(cmd_end_p);
	cmd_end_p += count_precision(cmd_end_p);
	cmd_end_p += count_type(cmd_end_p);
	return (cmd_end_p);
}
