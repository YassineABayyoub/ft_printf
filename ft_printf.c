/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	is_conv(char c)
{
	char	*set;
	int		i;

	set = "cspdiuxX%";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	print_format(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	return (write(1, "%", 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		n;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	n = 0;
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (va_end(args), -1);
		if (format[i] == '%' && is_conv(format[i + 1]))
			n += print_format(&args, format[++i]);
		else
			n += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (n);
}
