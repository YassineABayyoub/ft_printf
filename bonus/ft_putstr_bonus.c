/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_padded(char *s, int len, t_options o)
{
	int	count;

	count = 0;
	if (!o.minus)
		count += print_padding(' ', o.width - len);
	count += write(1, s, len);
	if (o.minus)
		count += print_padding(' ', o.width - len);
	return (count);
}

int	ft_putchar_opt(char c, t_options o)
{
	return (put_padded(&c, 1, o));
}

int	ft_putstr_opt(char *s, t_options o)
{
	int	len;

	if (!s)
	{
		s = "(null)";
		if (o.dot && o.precision < 6)
			s = "";
	}
	len = ft_strlen(s);
	if (o.dot && o.precision < len)
		len = o.precision;
	return (put_padded(s, len, o));
}
