/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	parse_flags(t_options *options, const char *str, int j)
{
	while (is_flag(str[j]))
	{
		if (str[j] == '-')
			options->minus = 1;
		else if (str[j] == '0')
			options->zero = 1;
		else if (str[j] == '+')
			options->plus = 1;
		else if (str[j] == ' ')
			options->space = 1;
		else
			options->hash = 1;
		j++;
	}
	return (j);
}

int	parse_number(int *nbr, const char *str, int j)
{
	while (is_digit(str[j]))
	{
		if (*nbr < 100000000)
			*nbr = *nbr * 10 + (str[j] - '0');
		j++;
	}
	return (j);
}
