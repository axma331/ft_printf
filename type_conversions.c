/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:05 by feschall          #+#    #+#             */
/*   Updated: 2021/03/05 17:43:42 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void output_type_s(const char *str,t_struct *cr)
{
	cr->len_str = ft_strlen(str);
	if (!str)
		str = "(null)";
	if (cr->width >= cr->len_str && cr->precision)
	{
		if (cr->precision > 0)
			cr->len_str = cr->precision;
		cr->len_tmp = (cr->width - cr->len_str);
		if (!(cr->flag & F_MINS))
			ft_putstr(str, cr->len_str, cr);
		while (cr->len_tmp-- > 0)
			cr->rezult += write(1, " ", 1);
		if (cr->flag & F_MINS)
			ft_putstr(str, cr->len_str, cr);
	}
}
