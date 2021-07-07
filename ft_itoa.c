/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:42:36 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/05/07 15:10:38 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoa_len(int n)
{
	int	r;

	if (n == 0)
		return (1);
	r = 0;
	if (n < 0)
		r++;
	while (n)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int n, t_len_for_command *print_len)
{
	int		minus;
	int		len_n;
	char	*char_n;

	len_n = ft_itoa_len(n);
	print_len->type = len_n;
	char_n = (char *)malloc(len_n + 1);
	if (char_n == NULL)
		return (NULL);
	if (n >= 0)
		minus = 0;
	if (n < 0)
	{
		char_n[0] = '-';
		minus = 1;
	}
	while (len_n-- > minus)
	{
		if (n >= 0)
			char_n[len_n] = '0' + n % 10 * 1;
		else if (n < 0)
			char_n[len_n] = '0' + n % 10 * -1;
		n /= 10;
	}
	return (char_n);
}
