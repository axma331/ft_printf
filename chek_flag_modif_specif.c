/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_flag_modif_specif.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:27 by feschall          #+#    #+#             */
/*   Updated: 2021/03/09 18:44:57 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_f_v(t_struct *ts)
{
    ts->flag = F_NUL;
	ts->result = 0;
	ts->width = 0;
	ts->precision = 0;
	ts->neg = 0;
	ts->len_str = 0;
	ts->len_tmp = 0;
	ts->s_z = " ";
}

void	check_flag(const char *str, t_struct *ts)
{
	if (str[ts->i] == '-')
	{
		ts->flag = ts->flag | F_MIN;
		ts->i++;
	}
	if (str[ts->i] == '0')
	{
		ts->flag = ts->flag | F_ZRO;
			if (ts->flag & F_MIN)
				ts->flag = F_MIN;
			if (!(ts->flag & F_MIN))
				ts->s_z = "0";
		ts->i++;
	}
}

void	check_width(const char *str, va_list ap, t_struct *ts)
{
	if (str[ts->i] == '*')
	{
		ts->width = va_arg(ap, int);
		if (ts->width < 0)
		{
			ts->width *= -1;
			ts->flag = ts->flag | F_MIN;
		}
	}
	else
		while ('0' <= str[ts->i] && str[ts->i] <= '9')
			ts->width = ts->width * 10 + (str[ts->i++] - '0');
}

void	check_precision(const char *str, va_list ap, t_struct *ts)
{
	if (str[ts->i] == '.')
	{
		ts->flag = ts->flag | F_DOT;
		if(str[ts->i++] == '*' || ('0' <= str[ts->i] && str[ts->i] <= '9'))
		{
			if (str[ts->i] == '*')
			{
				ts->precision = va_arg(ap, int);
				ts->i++;
			}
			else
				while ('0' <= str[ts->i] && str[ts->i] <= '9')
					ts->precision = ts->precision * 10 + (str[ts->i++] - '0');
		}
		else
			ts->precision = 0;
	}
}

void	check_type(const char *str, va_list ap, t_struct *ts)
{
	if (str[ts->i] == 's')
		output_type_s(va_arg(ap, char*), ts);
	if (str[ts->i] == 'c')
		output_type_c(va_arg(ap, int), ts);
	if (str[ts->i] == 'd' || str[ts->i] == 'i' || str[ts->i] == 'u')
		output_type_di(va_arg(ap, int), ts);
	if (str[ts->i] == 'u')
		output_type_u(va_arg(ap, unsigned int), ts);
	// if (str[ts->i] == 's')
	// 	output_type_s(va_arg(ap, char*), ts);
	// if (str[ts->i] == 's')
	// 	output_type_s(va_arg(ap, char*), ts);
	// if (str[ts->i] == 's')
	// if (str[ts->i] == '%')
	// 	output_type_s(va_arg(ap, char*), ts);
		ts->i++;
}
