/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:31:51 by feschall          #+#    #+#             */
/*   Updated: 2021/03/12 08:32:02 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_putstr(const char *str, int len, t_struct *ts)
{
	while (str && len-- > 0)
	{
		ts->result += write(1, str, 1);
		str++;
	}
	return (ts->result);
}

int		count_b(long int n, t_struct *ts)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = (-1) * n;
		i++;
	}
	while (n >= ts->dev)
	{
		n /= ts->dev;
		i++;
	}
	return (i);
}

char	*ft_litoa_b(long int n, t_struct *ts)
{
	char		*str_n;
	char		ascii;
	long int	num;
	int			i;

	i = 0;
	if (!(str_n = (char *)malloc(sizeof(char) * (count_b(n, ts) + 1))))
		return (0);
	if (n < 0)
		str_n[0] = '-';
	num = n;
	if (num < 0)
		num = -num;
	str_n[count_b(n, ts) - i++] = '\0';
	while (num >= 10)
	{
		ascii = (num % ts->dev > 9) ? ts->ca : '0';
		str_n[count_b(n, ts) - i++] = (num % ts->dev) + ascii;
		num /= ts->dev;
	}
	str_n[count_b(n, ts) - i] = (num % ts->dev) + '0';
	return (str_n);
}
