/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_cxpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:06:41 by feschall          #+#    #+#             */
/*   Updated: 2021/03/12 21:38:16 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_type_c(int c, t_struct *ts)
{
	if (ts->flag & F_MIN)
		ts->result += write(1, &c, 1);
	while (ts->wid-- > 1)
		ts->result += write(1, " ", 1);
	if (!(ts->flag & F_MIN))
		ts->result += write(1, &c, 1);
}

void	output_type_x(unsigned int n, t_struct *ts)
{
	char	*tmp;

	ts->dev = 16;
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

void	output_type_p(unsigned long n, t_struct *ts)
{
	char	*tmp;

	ts->dev = 16;
	ts->ox = 2;
	tmp = ft_litoa_b(n, ts);
	n == 0 ? ts->str_n = "0" : 0;
	ts->str_n = (ts->prcs == 0 && n == 0) ? "" : tmp;
	ts->len_s = ft_strlen(ts->str_n);
	ts->len_t = ts->len_s + ts->ox;
	if (ts->flag & F_MIN)
		output_type_dix_lt(ts);
	else
		output_type_dix_rt(ts);
	free(tmp);
}

void	output_type_per(t_struct *ts)
{
	ts->len_t = 1;
	if (ts->flag & F_MIN)
	{
		while (ts->prcs > 1)
		{
			ts->result += write(1, "0", 1);
			ts->len_t++;
		}
		ts->result += write(1, "%", 1);
		while (ts->len_t++ < ts->wid)
			ts->result += write(1, " ", 1);
	}
	else
	{
		ts->len_s = (ts->len_s < ts->prcs) ? ts->prcs : 1;
		while (!(ts->flag & F_ZRO) && (ts->wid > ts->len_s++))
			ts->result += write(1, " ", 1);
		while ((ts->flag & F_ZRO) && ts->len_s++ < ts->wid)
			ts->result += write(1, "0", 1);
		while (ts->prcs > ts->len_t++)
			ts->result += write(1, "0", 1);
		ts->result += write(1, "%", 1);
	}
}
