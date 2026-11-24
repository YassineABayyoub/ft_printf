/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	init_options(t_options *options)
{
	options->minus = 0;
	options->zero = 0;
	options->plus = 0;
	options->space = 0;
	options->hash = 0;
	options->width = 0;
	options->dot = 0;
	options->precision = 0;
}

static void	apply_rules(t_options *options, char conv)
{
	if (options->minus)
		options->zero = 0;
	if (options->plus)
		options->space = 0;
	if (options->dot && (conv == 'd' || conv == 'i' || conv == 'u'
			|| conv == 'x' || conv == 'X' || conv == 'p'))
		options->zero = 0;
}

int	is_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	check_format(t_options *options, const char *str)
{
	int	j;

	init_options(options);
	j = parse_flags(options, str, 0);
	j = parse_number(&options->width, str, j);
	if (str[j] == '.')
	{
		options->dot = 1;
		j = parse_number(&options->precision, str, j + 1);
	}
	if (!is_conv(str[j]))
		return (-1);
	apply_rules(options, str[j]);
	return (j);
}
