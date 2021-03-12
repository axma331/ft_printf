/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_csudi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:05 by feschall          #+#    #+#             */
/*   Updated: 2021/03/12 11:16:35 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_type_c(int c, t_struct *ts)
{
	if (ts->flag & F_MIN)
		ts->result += write(1, &c, 1);
	while (ts->width-- > 1)
		ts->result += write(1, " ", 1);
	if (!(ts->flag & F_MIN))
		ts->result += write(1, &c, 1);
}

void	output_type_s(const char *str, t_struct *ts)
{
	if (!str)
		str = "(null)";
	ts->len_s = ft_strlen(str);
	if (ts->flag & F_DOT && ts->prcs > -1 && ts->prcs < ts->len_s)
		ts->len_s = ts->prcs;
	ts->len_t = (ts->width - ts->len_s);
	if (ts->flag & F_MIN)
		ft_putstr(str, ts->len_s, ts);
	while (ts->len_t-- > 0)
		ts->result += write(1, " ", 1);
	if (!(ts->flag & F_MIN))
		ft_putstr(str, ts->len_s, ts);
}

void	output_type_u(unsigned int n, t_struct *ts)
{
	ts->str_n = (ts->prcs == 0 && n == 0) ? "" : ft_litoa_b(n, ts);
	ts->len_s = ft_strlen(ts->str_n);
	ts->len_t = ts->len_s;
	if (ts->flag & F_MIN)
	{
		while (ts->prcs > ts->len_t)
		{
			ts->result += write(1, "0", 1);
			ts->len_t++;
		}
		ts->result += write(1, ts->str_n, ft_strlen(ts->str_n));
		while (ts->len_t++ < ts->width)
			ts->result += write(1, " ", 1);
	}
	else
	{
		ts->len_s < ts->prcs ? ts->len_s = ts->prcs : 0;
		while (!(ts->flag & F_ZRO) && (ts->width > ts->len_s++))
			ts->result += write(1, " ", 1);
		while ((ts->flag & F_ZRO) && ts->len_s++ < ts->width)
			ts->result += write(1, "0", 1);
		while (ts->prcs > ts->len_t++)
			ts->result += write(1, "0", 1);
		ts->result += write(1, ts->str_n, ft_strlen(ts->str_n));
	}
}

void	output_type_di(int n, t_struct *ts)
{
	ts->neg = (n < 0) ? 1 : 0;
	ts->str_n = (ts->prcs == 0 && n == 0) ? "" : (ts->neg + ft_litoa_b(n, ts));
	ts->len_s = ft_strlen(ts->str_n);
	ts->len_t = ts->len_s;
	if (ts->flag & F_MIN)
		output_type_dix_lt(ts);
	else
	{
		if (ts->len_s < ts->prcs)
			ts->len_s = ts->prcs;
		while (!(ts->flag & F_ZRO) && (ts->width > ts->neg + ts->len_s++))
			ts->result += write(1, " ", 1);
		if (ts->neg)
			ts->result += write(1, "-", 1);
		while ((ts->flag & F_ZRO) && ts->len_s++ + ts->neg < ts->width)
			ts->result += write(1, "0", 1);
		while (ts->prcs > ts->len_t++)
			ts->result += write(1, "0", 1);
		ts->result += write(1, ts->str_n, ft_strlen(ts->str_n));
	}
}

void	output_type_dix_lt(t_struct *ts)
{
	if (ts->neg)
		ts->result += write(1, "-", 1);
	while (ts->len_t < ts->prcs)
	{
		ts->result += write(1, "0", 1);
		ts->len_t++;
	}
	if (ts->dev == 16)
		ts->result += write(1, "0x", 2);
	ts->result += write(1, ts->str_n, ts->len_s);
	while (ts->len_t++ < (ts->width - ts->neg))
		ts->result += write(1, " ", 1);
}
