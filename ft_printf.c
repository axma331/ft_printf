/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:34:09 by feschall          #+#    #+#             */
/*   Updated: 2021/03/06 09:16:26 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list ap;
	t_struct ts;
	t_type t;

	reset_f_v(&ts);
	va_start(ap, str);
	while (str[ts.i])
	{
		if (str[ts.i] != '%')
			ts.rezult+= write(1, &str[ts.i++], 1);
		else
		{
			ts.i++;
			check_flag(str, &ts);
			check_width(str, ap, &ts);
			check_precision(str, ap, &ts);
			check_type(str, &ts);
			// data_conversion();
		}
	}
	va_end (ap);
	return (ts.rezult);
}