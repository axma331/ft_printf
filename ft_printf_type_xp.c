/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_xp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:06:41 by feschall          #+#    #+#             */
/*   Updated: 2021/03/11 23:44:11 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_type_x(unsigned int n, t_struct *ts)
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
