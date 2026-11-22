/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long n, char *base)
{
	unsigned long	len;
	int				count;

	len = 0;
	while (base[len])
		len++;
	count = 0;
	if (n >= len)
		count += ft_putbase(n / len, base);
	count += write(1, &base[n % len], 1);
	return (count);
}

int	ft_puthex(unsigned int n, char conv)
{
	if (conv == 'x')
		return (ft_putbase(n, "0123456789abcdef"));
	return (ft_putbase(n, "0123456789ABCDEF"));
}
