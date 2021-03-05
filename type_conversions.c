/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:05 by feschall          #+#    #+#             */
/*   Updated: 2021/03/05 19:27:04 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void output_type_s(const char *str,t_struct *ts)
{
	ts->len_str = ft_strlen(str);
	if (!str)
		str = "(null)";
	if (ts->width >= ts->len_str && ts->precision)
	{
		if (ts->precision > 0)
			ts->len_str = ts->precision;
		ts->len_tmp = (ts->width - ts->len_str);
		if (!(ts->flag & F_MINS))
			ft_putstr(str, ts->len_str, ts);
		while (ts->len_tmp-- > 0)
			ts->rezult += write(1, " ", 1);
		if (ts->flag & F_MINS)
			ft_putstr(str, ts->len_str, ts);
	}
}
