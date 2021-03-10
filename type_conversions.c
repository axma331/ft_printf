/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:05 by feschall          #+#    #+#             */
/*   Updated: 2021/03/10 20:10:44 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_type_s(const char *str_n, t_struct *ts)
{
	ts->len_s = ft_strlen(str_n);
	if (!str_n)
		str_n = "(null)";
	if (ts->width >= ts->len_s) //&& ts->prcs
	{
		if (ts->prcs > 0)
			ts->len_s = ts->prcs;
		ts->len_t = (ts->width - ts->len_s);
		if (ts->flag & F_MIN)
			ft_putstr(str_n, ts->len_s, ts);
		while (ts->len_t-- > 0)
			ts->result += write(1, " ", 1);
		if (!(ts->flag & F_MIN))
			ft_putstr(str_n, ts->len_s, ts);
	}
	else
		ft_putstr(str_n, ts->len_s, ts);
}

void	output_type_c(int c, t_struct *ts)
{
	if (ts->flag & F_MIN)
		ts->result += write(1, &c, 1);
	while (ts->width-- > 1)
			ts->result += write(1, " ", 1);
	if (!(ts->flag & F_MIN))
		ts->result += write(1, &c, 1);
}

void	output_type_di(int n, t_struct *ts)
{
	char	*str_n;

	ts->neg = (n < 0) ? 1 : 0;
	str_n = (ts->prcs == 0 && n == 0) ? "" : (ts->neg + ft_itoa(n));
	ts->len_s = ft_strlen(str_n);
	ts->len_t = ts->len_s;
	if(ts->flag & F_MIN)
	{
		if (ts->neg)
			ts->result += write(1, "-", 1);
		while (ts->len_t < ts->prcs)
		{
			ts->result += write(1, "0", 1);
			ts->len_t++;
		}
		ts->result += write(1, str_n, ts->len_s);
		while (ts->len_t++ < (ts->width - ts->neg))
			ts->result += write(1, " ", 1);	
	}
	else
	{
		if (ts->len_s < ts->prcs)
			ts->len_s = ts->prcs;
		while (!(ts->flag & F_ZRO) && (ts->width > ts->neg + ts->len_s++)) //ts->prcs != -1 && 
			ts->result += write(1, " ", 1);
		if (ts->neg)
			ts->result += write(1, "-", 1);
		while ((ts->flag & F_ZRO) && ts->len_s++ + ts->neg < ts->width)
			ts->result += write(1, "0", 1);
		while (ts->prcs > ts->len_t++)
			ts->result += write(1, "0", 1);
		ts->result += write(1, str_n, ft_strlen(str_n));	
	}
}

// void	output_type_u(unsigned int n, t_struct *ts)
// {
	
// }
