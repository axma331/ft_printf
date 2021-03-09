/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:31:51 by feschall          #+#    #+#             */
/*   Updated: 2021/03/09 17:02:01 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_strlen(const char *s)
{
	int len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

int 	ft_putstr(const char *str, int len, t_struct *ts)
{
	while (str && len-- > 0)
	{
		ts->result += write(1, str, 1);
		str++;
	}
	return (ts->result);
}

int		count(long int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa( int n)
{
	char		*str_n;
	long int	num;
	int			i;

	i = 0;
	if (!(str_n = (char *)malloc(sizeof(char) * count(n) + 1)))
		return (0);
	if (n < 0)
		str_n[0] = '-';
	num = n;
	if (num < 0)
		num  = -num;
	str_n[count(n) - i++] = '\0';
	while (num > 9)
	{
		str_n[count(n) - i++] = (num % 10) + '0';
		num /= 10;
	} 
	str_n[count(n) - i] = (num % 10) + '0';
	return (str_n);
}
