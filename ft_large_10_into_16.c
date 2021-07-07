/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_large_10_into_16.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:39:51 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/06 15:31:47 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_large_large_x_arg_len(unsigned int large_x_arg)
{
	unsigned int	r;

	if (large_x_arg == 0)
		return (1);
	r = 0;
	while (large_x_arg)
	{
		large_x_arg /= 16;
		r++;
	}
	return (r);
}

char	*ft_large_10_into_16(unsigned int large_x_arg,
		t_len_for_command *print_len)
{
	unsigned int	len_large_x_arg;
	char			*char_large_x_arg;

	len_large_x_arg = ft_large_large_x_arg_len(large_x_arg);
	print_len->type = len_large_x_arg;
	char_large_x_arg = (char *)malloc(len_large_x_arg + 1);
	if (char_large_x_arg == NULL)
		return (NULL);
	while (len_large_x_arg-- > 0)
	{
		if (large_x_arg % 16 >= 10)
			char_large_x_arg[len_large_x_arg] = large_x_arg % 16 + ('A' - 10);
		else
			char_large_x_arg[len_large_x_arg] = large_x_arg % 16 + '0';
		large_x_arg /= 16;
	}
	return (char_large_x_arg);
}
