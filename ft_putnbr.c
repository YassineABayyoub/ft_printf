/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	if (n < 0)
	{
		count = write(1, "-", 1);
		return (count + ft_putbase(-(unsigned long)n, "0123456789"));
	}
	return (ft_putbase(n, "0123456789"));
}

int	ft_putunsigned(unsigned int n)
{
	return (ft_putbase(n, "0123456789"));
}
