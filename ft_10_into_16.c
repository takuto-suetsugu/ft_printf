/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_into_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:17:45 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 23:28:23 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_arg_len(long x_arg)
{
	long	r;

	if (x_arg == 0)
		return (1);
	r = 0;
	while (x_arg)
	{
		x_arg /= 16;
		r++;
	}
	return (r);
}

char	*ft_10_into_16(long x_arg, t_len_for_command *print_len)
{
	long	len_x_arg;
	char	*char_x_arg;

	len_x_arg = ft_x_arg_len(x_arg);
	print_len->type += len_x_arg;
	char_x_arg = (char *)malloc(len_x_arg + 1);
	if (char_x_arg == NULL)
		return (NULL);
	while (len_x_arg-- > 0)
	{
		if (x_arg % 16 >= 10)
			char_x_arg[len_x_arg] = x_arg % 16 + ('a' - 10);
		else
			char_x_arg[len_x_arg] = x_arg % 16 + '0';
		x_arg /= 16;
	}
	return (char_x_arg);
}
