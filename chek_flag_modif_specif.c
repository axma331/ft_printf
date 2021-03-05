/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_flag_modif_specif.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:27 by feschall          #+#    #+#             */
/*   Updated: 2021/03/05 17:53:06 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void reset_f_v(t_struct *cr)
{
    cr->flag = F_NULL;
	cr->rezult = 0;
	cr->width = 0;
	cr->precision = 0;
	cr->len_str = 0;
}

const char *check_flag(const char *str, t_struct *cr)
{
	if (*str == '-')
	{
		cr->flag = cr->flag | F_MINS;
		str++;
	}
	if (*str == '0')
	{
		cr->flag = cr->flag | F_ZERO;
			if (cr->flag & F_MINS)
			cr->flag = F_MINS;
		str++;
	}
	return str;
}

const char *check_width(const char *str, va_list ap, t_struct *cr)
{
	if (*str == '*')
		cr->width = va_arg(ap, int);
		if (cr->width < 0)
		{
			cr->width *= -1;
			cr->flag = cr->flag | F_MINS;
		}
	else
		while ('0' <= *str && *str <= '9')
		{
			cr->width = cr->width * 10 + (*str - '0');
			str++;
		}
	return str;
}

const char *check_precision(const char *str, va_list ap, t_struct *cr)
{
	if (*str == '.')
	{
		cr->flag = cr->flag | F_DOT;
		if(*str++ == '*' || ('0' <= *str && *str <= '9'))
		{
			if (*str == '*')
			{
				cr->precision = va_arg(ap, int);
				str++;
			}
			else
				while ('0' <= *str && *str <= '9')
				{
					cr->precision = cr->precision * 10 + (*str - '0');
					str++;
				}
		}
		else
			cr->precision = 0;
	}
	return str;
}

const char *check_type(const char *str, t_struct *cr)
{
	if (*str == 's')
	{
		output_type_s(str, cr);
		str++;
	}
	return str;
}