/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:34:09 by feschall          #+#    #+#             */
/*   Updated: 2021/03/05 17:59:58 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list ap;
	t_struct *cr;

	reset_f_v(cr);
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			cr->rezult+= write(1, str, 1);
		else
		{
			if (*str == '%')
				str++;
			str = check_flag(str, cr);
			str = check_width(str, ap, cr);
			str = check_precision(str, ap, cr);
			str = check_type(str, cr);
			// data_conversion();
		}
		str++;
	}
	va_end (ap);
	return (cr->rezult);
}

int main()
{
	   printf("test1 text%-10.5s\n", "1234567890");
	ft_printf("test2 text%-10.5s\n", "1234567890");
	    printf("test3 text%10.5s\n", "1234567890");
	 ft_printf("test4 text%10.5s\n", "1234567890");
   return (0);
}
