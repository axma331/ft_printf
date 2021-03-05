/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:31:51 by feschall          #+#    #+#             */
/*   Updated: 2021/03/05 19:27:30 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(const char *s)
{
	int len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

int ft_putstr(const char *str, int len, t_struct *ts)
{
	while (*str && len-- > 0)
		ts->rezult += write(1, str++, 1);
	return (ts->rezult);
}
