/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_format(va_list *args, char c, t_options o)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int), o));
	if (c == 'u' || c == 'x' || c == 'X')
		return (ft_putunsigned(va_arg(*args, unsigned int), o, c));
	if (c == 'c')
		return (ft_putchar_opt((char)va_arg(*args, int), o));
	if (c == 's')
		return (ft_putstr_opt(va_arg(*args, char *), o));
	if (c == 'p')
		return (ft_putptr(va_arg(*args, void *), o));
	return (write(1, "%", 1));
}

static int	handle_spec(va_list *args, const char *format, int *i)
{
	t_options	options;
	int			j;

	j = check_format(&options, &format[*i + 1]);
	if (j < 0)
	{
		*i += 1;
		return (write(1, "%", 1));
	}
	*i += j + 2;
	return (print_format(args, format[*i - 1], options));
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
		if (format[i] != '%')
			n += write(1, &format[i++], 1);
		else if (!format[i + 1])
		{
			n = -1;
			break ;
		}
		else
			n += handle_spec(&args, format, &i);
	}
	va_end(args);
	return (n);
}
