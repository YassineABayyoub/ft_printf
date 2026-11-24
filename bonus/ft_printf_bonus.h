/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/21 13:30:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/21 13:30:00 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_options
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hash;
	int	width;
	int	dot;
	int	precision;
}	t_options;

int				ft_printf(const char *format, ...);
int				check_format(t_options *options, const char *str);
int				is_conv(char c);
int				parse_flags(t_options *options, const char *str, int j);
int				parse_number(int *nbr, const char *str, int j);
int				ft_strlen(const char *s);
unsigned long	ft_abs(int n);
int				num_len(unsigned long n, unsigned int base);
int				put_unsigned(unsigned long n, char *base, unsigned int blen);
int				print_padding(char c, int n);
int				put_number(t_options o, char *prefix, unsigned long n,
					char *base);
int				put_padded(char *s, int len, t_options o);
int				ft_putnbr(int n, t_options o);
int				ft_putunsigned(unsigned int n, t_options o, char conv);
int				ft_putptr(void *p, t_options o);
int				ft_putchar_opt(char c, t_options o);
int				ft_putstr_opt(char *s, t_options o);

#endif
