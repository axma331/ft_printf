/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:34:09 by feschall          #+#    #+#             */
/*   Updated: 2021/03/12 21:41:37 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_struct	ts;

	ts.i = 0;
	ts.result = 0;
	reset_f_v(&ts);
	va_start(ap, str);
	while (str[ts.i])
	{
		if (str[ts.i] != '%')
			ts.result += write(1, &str[ts.i++], 1);
		else
		{
			ts.i++;
			check_f_w_p(str, ap, &ts);
			check_type(str, ap, &ts);
			reset_f_v(&ts);
		}
	}
	va_end(ap);
	return (ts.result);
}
