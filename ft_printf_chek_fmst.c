/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chek_fmst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:27 by feschall          #+#    #+#             */
/*   Updated: 2021/03/12 19:23:03 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_f_v(t_struct *ts)
{
	ts->flag = F_NUL;
	ts->wid = 0;
	ts->prcs = -1;
	ts->neg = 0;
	ts->len_s = 0;
	ts->len_t = 0;
	ts->dev = 10;
	ts->ca = 87;
	ts->ox = 0;
	ts->str_n = NULL;
}

void	check_flag_width(const char *str, va_list ap, t_struct *ts)
{
	if (str[ts->i] == '-')
	{
		ts->flag = ts->flag | F_MIN;
		ts->flag = ts->flag & 0b11111101;
		ts->i++;
	}
	if (str[ts->i] == '0' && !(ts->flag & F_MIN))
	{
		ts->flag = ts->flag | F_ZRO;
		ts->i++;
	}
	if (str[ts->i] == '*')
	{
		ts->wid = va_arg(ap, int);
		if (ts->wid < 0)
		{
			ts->wid *= -1;
			ts->flag = ts->flag | F_MIN;
			ts->flag = ts->flag & 0b11111101;
		}
		ts->i++;
	}
	else
		while ('0' <= str[ts->i] && str[ts->i] <= '9')
			ts->wid = ts->wid * 10 + (str[ts->i++] - '0');
}

void	check_precision(const char *str, va_list ap, t_struct *ts)
{
	if (str[ts->i] == '.')
	{
		ts->flag = ts->flag | F_DOT;
		ts->prcs = 0;
		if (str[++ts->i] == '*' || ('0' <= str[ts->i] && str[ts->i] <= '9'))
		{
			if (str[ts->i] == '*')
			{
				ts->prcs = va_arg(ap, int);
				ts->i++;
				ts->flag = ts->prcs < 0 ? ts->flag & 0b11111111 :
											ts->flag & 0b11111101;
			}
			else
			{
				while ('0' <= str[ts->i] && str[ts->i] <= '9')
					ts->prcs = ts->prcs * 10 + (str[ts->i++] - '0');
				ts->flag = ts->flag & 0b11111101;
			}
		}
	}
}

void	check_f_w_p(const char *str, va_list ap, t_struct *ts)
{
	while (str[ts->i] == '-' || str[ts->i] == '0' || str[ts->i] == '*' ||
			str[ts->i] == '.' || ('0' <= str[ts->i] && str[ts->i] <= '9'))
	{
		check_flag_width(str, ap, ts);
		check_precision(str, ap, ts);
	}
}

int		check_type(const char *str, va_list ap, t_struct *ts)
{
	if (str[ts->i] == 'c')
		output_type_c(va_arg(ap, int), ts);
	else if (str[ts->i] == 's')
		output_type_s(va_arg(ap, char*), ts);
	else if (str[ts->i] == 'u')
		output_type_u(va_arg(ap, unsigned int), ts);
	else if (str[ts->i] == 'd' || str[ts->i] == 'i')
		output_type_di(va_arg(ap, int), ts);
	else if (str[ts->i] == 'x' || str[ts->i] == 'X')
	{
		ts->ca = str[ts->i] == 'X' ? 55 : 87;
		output_type_x(va_arg(ap, unsigned int), ts);
	}
	else if (str[ts->i] == 'p')
		output_type_p(va_arg(ap, unsigned long), ts);
	else if (str[ts->i] == '%')
		output_type_per(ts);
	else
		return (-1);
	ts->i++;
	return (0);
}
