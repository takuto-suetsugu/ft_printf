/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_into_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:24:35 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 19:45:11 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_arg_len(unsigned int u_arg)
{
	unsigned int	r;

	if (u_arg == 0)
		return (1);
	r = 0;
	while (u_arg)
	{
		u_arg /= 10;
		r++;
	}
	return (r);
}

char	*ft_unsigned_into_str(unsigned int u_arg, t_len_for_command *cmd_len)
{
	unsigned int	len_u_arg;
	char			*char_u_arg;

	len_u_arg = ft_u_arg_len(u_arg);
	cmd_len->type = len_u_arg;
	char_u_arg = (char *)malloc(len_u_arg + 1);
	if (char_u_arg == NULL)
		return (NULL);
	while (len_u_arg-- > 0)
	{
		char_u_arg[len_u_arg] = '0' + u_arg % 10;
		u_arg /= 10;
	}
	return (char_u_arg);
}
