/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:05 by feschall          #+#    #+#             */
/*   Updated: 2021/03/09 19:09:42 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_type_s(const char *str_n, t_struct *ts)
{
	ts->len_str = ft_strlen(str_n);
	if (!str_n)
		str_n = "(null)";
	if (ts->width >= ts->len_str) //&& ts->precision
	{
		if (ts->precision > 0)
			ts->len_str = ts->precision;
		ts->len_tmp = (ts->width - ts->len_str);
		if (ts->flag & F_MIN)
			ft_putstr(str_n, ts->len_str, ts);
		while (ts->len_tmp-- > 0)
			ts->result += write(1, " ", 1);
		if (!(ts->flag & F_MIN))
			ft_putstr(str_n, ts->len_str, ts);
	}
	else
		ft_putstr(str_n, ts->len_str, ts);
}

void	output_type_c(int c, t_struct *ts)
{
	if (ts->flag & F_MIN)
		ts->result += write(1, &c, 1);
	while (ts->width-- > 1)
			ts->result += write(1, " ", 1);
	if (!(ts->flag & F_MIN))
		ts->result += write(1, &c, 1);
}

void	output_type_di(int n, t_struct *ts)
{
	char	*str_n;
	
	ts->neg = (n < 0) ? 1 : 0;
	str_n = ft_itoa(n) + ts->neg;
	ts->len_str = ft_strlen(str_n);
	if(ts->flag & F_MIN)
	{
		if(ts->neg)
			ts->result += write(1, "-", 1);
		ts->result += write(1, str_n, (ts->len_str - ts->neg));
	}
	if (ts->width)
		if ((ts->len_tmp = ts->width - ts->len_str - ts->neg) > 0)
		{
			while (ts->len_tmp-- > 0)
				ts->result += write(1, ts->s_z, 1);
		}
	if (!(ts->flag & F_MIN))
	{
		if(ts->neg)
			ts->result += write(1, "-", 1);
		ts->result += write(1, str_n, ts->len_str);
	}
}

void	output_type_u(unsigned int n, t_struct *ts)
{
	char	*str_n;
	
	str_n = ft_itoa(n);
	ts->len_str = ft_strlen(str_n);
	ts->result += write(1, str_n, ft_strlen(str_n));
}
