/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*get_ptr_prefix(t_options o)
{
	if (o.plus)
		return ("+0x");
	if (o.space)
		return (" 0x");
	return ("0x");
}

int	ft_putptr(void *p, t_options o)
{
	if (!p)
		return (put_padded("(nil)", 5, o));
	return (put_number(o, get_ptr_prefix(o), (unsigned long)p,
			"0123456789abcdef"));
}
