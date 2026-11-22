/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numutils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

unsigned long	ft_abs(int n)
{
	if (n < 0)
		return (-(unsigned long)n);
	return (n);
}

int	num_len(unsigned long n, unsigned int base)
{
	int	len;

	len = 1;
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	put_unsigned(unsigned long n, char *base, unsigned int blen)
{
	int	count;

	count = 0;
	if (n >= blen)
		count += put_unsigned(n / blen, base, blen);
	count += write(1, &base[n % blen], 1);
	return (count);
}

int	print_padding(char c, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += write(1, &c, 1);
		n--;
	}
	return (count);
}
