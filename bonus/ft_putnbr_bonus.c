/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	get_sign(int n, t_options op)
{
	if (n < 0)
		return ('-');
	if (op.plus)
		return ('+');
	if (op.space)
		return (' ');
	return (0);
}

int	ft_putnbr(int n, t_options op)
{
	char	prefix[2];

	prefix[0] = get_sign(n, op);
	prefix[1] = 0;
	return (put_number(op, prefix, ft_abs(n), "0123456789"));
}
