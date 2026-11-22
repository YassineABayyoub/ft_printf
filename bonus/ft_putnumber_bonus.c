/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_zeros(t_options o, int len, int plen)
{
	int	zeros;

	zeros = 0;
	if (o.dot && o.precision > len)
		zeros = o.precision - len;
	if (o.zero)
		zeros = o.width - len - plen;
	if (zeros < 0)
		zeros = 0;
	return (zeros);
}

int	put_number(t_options o, char *prefix, unsigned long n, char *base)
{
	int	len;
	int	plen;
	int	zeros;
	int	pad;
	int	count;

	plen = ft_strlen(prefix);
	len = num_len(n, ft_strlen(base));
	if (n == 0 && o.dot && o.precision == 0)
		len = 0;
	zeros = get_zeros(o, len, plen);
	pad = o.width - len - zeros - plen;
	count = 0;
	if (!o.minus)
		count += print_padding(' ', pad);
	count += write(1, prefix, plen);
	count += print_padding('0', zeros);
	if (len)
		count += put_unsigned(n, base, ft_strlen(base));
	if (o.minus)
		count += print_padding(' ', pad);
	return (count);
}

static char	*get_prefix(t_options o, unsigned int n, char *prefix)
{
	if (o.hash && n)
		return (prefix);
	return ("");
}

int	ft_putunsigned(unsigned int n, t_options o, char conv)
{
	if (conv == 'u')
		return (put_number(o, "", n, "0123456789"));
	if (conv == 'x')
		return (put_number(o, get_prefix(o, n, "0x"), n, "0123456789abcdef"));
	return (put_number(o, get_prefix(o, n, "0X"), n, "0123456789ABCDEF"));
}
