/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_sudi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:05 by feschall          #+#    #+#             */
/*   Updated: 2021/03/12 21:34:01 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_type_s(const char *str, t_struct *ts)
{
	if (!str)
		str = "(null)";
	ts->len_s = ft_strlen(str);
	if (ts->flag & F_DOT && ts->prcs > -1 && ts->prcs < ts->len_s)
		ts->len_s = ts->prcs;
	ts->len_t = (ts->wid - ts->len_s);
	if (ts->flag & F_MIN)
		ft_putstr(str, ts->len_s, ts);
	while (ts->len_t-- > 0)
		ts->result += write(1, " ", 1);
	if (!(ts->flag & F_MIN))
		ft_putstr(str, ts->len_s, ts);
}

void	output_type_u(unsigned int n, t_struct *ts)
{
	char	*tmp;

	tmp = ft_litoa_b(n, ts);
	ts->str_n = (ts->prcs == 0 && n == 0) ? "" : tmp;
	ts->len_s = ft_strlen(ts->str_n);
	ts->len_t = ts->len_s;
	if (ts->flag & F_MIN)
		output_type_dix_lt(ts);
	else
		output_type_dix_rt(ts);
	free(tmp);
}

void	output_type_di(int n, t_struct *ts)
{
	char	*tmp;

	tmp = ft_litoa_b(n, ts);
	ts->neg = (n < 0) ? 1 : 0;
	ts->str_n = (ts->prcs == 0 && n == 0) ? NULL : (ts->neg + tmp);
	if (ts->str_n != NULL)
	{
		ts->len_s = ft_strlen(ts->str_n);
		ts->len_t = ts->len_s;
	}
	if (ts->flag & F_MIN)
		output_type_dix_lt(ts);
	else
		output_type_dix_rt(ts);
	free(tmp);
}

void	output_type_dix_lt(t_struct *ts)
{
	ts->neg ? ts->result += write(1, "-", 1) : 0;
	while (ts->len_t < ts->prcs)
	{
		ts->result += write(1, "0", 1);
		ts->len_t++;
	}
	ts->ox > 0 ? ts->result += write(1, "0x", ts->ox) : 0;
	ts->result += write(1, ts->str_n, ft_strlen(ts->str_n));
	while (ts->len_t++ < (ts->wid - ts->neg))
		ts->result += write(1, " ", 1);
}

void	output_type_dix_rt(t_struct *ts)
{
	ts->len_s < ts->prcs ? ts->len_s = ts->prcs : 0;
	while (!(ts->flag & F_ZRO) && (ts->wid > (ts->neg + ts->len_s++ + ts->ox)))
		ts->result += write(1, " ", 1);
	ts->neg > 0 ? ts->result += write(1, "-", 1) : 0;
	while ((ts->flag & F_ZRO) && ts->len_s++ + ts->neg < ts->wid)
		ts->result += write(1, "0", 1);
	while (ts->prcs > ts->len_t++)
		ts->result += write(1, "0", 1);
	ts->ox > 0 ? (ts->result += write(1, "0x", ts->ox)) : 0;
	ts->result += write(1, ts->str_n, ft_strlen(ts->str_n));
}
