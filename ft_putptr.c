/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int	count;

	if (!p)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	return (count + ft_putbase((unsigned long)p, "0123456789abcdef"));
}
