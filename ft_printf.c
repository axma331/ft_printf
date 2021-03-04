/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:34:09 by feschall          #+#    #+#             */
/*   Updated: 2021/03/04 21:40:02 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int ft_strlen(const char *s)
{
   int len;

   len = 0;
   while(s[len])
      len++;
   return (len);
}

int ft_putstr(char *str, int len, t_struct *check)
{	
	while (*str != '\0' && len-- > 0)
		check->rezult += write(1, str++, 1);
	return (check->rezult);
}

void ft_printf_s(char *str,t_struct *check)
	{
		int len_t;

		check->len_s = ft_strlen(str);

		if (check->width >= check->len_s && check->precision && !(check->flag & F_MINS))// Заполняем |<-
		{
			if (check->precision > 0)
				check->len_s = check->precision;
			len_t = (check->width - check->len_s); 
				while (len_t-- > 0)
					check->rezult += write(1, " ", 1);	// Заполняем пробелами левый край
			ft_putstr(str, check->len_s, check);	//Дозаполняем строку до конца
		}
		else if (check->width >= check->len_s && check->precision && (check->flag & F_MINS)) // Заполняем ->|
		{
			if (check->precision > 0)
				check->len_s = check->precision;
			ft_putstr(str, check->len_s, check);	//Заполняем строку указанной точности
			len_t = (check->width - check->len_s); 
				while (len_t-- > 0)
					check->rezult += write(1, " ", 1);	// Заполняем пробелами левый край
		}
	}


int ft_printf(const char *str, ...)
{
	t_struct *check;
	
	check->flag = F_NULL;
	check->rezult = 0;
	check->width = 0;
	check->precision = 0;
	check->len_s = 0;

   va_list ap;
   va_start(ap, str);
   while(*str != '\0')
   {
	   if (*str != '%')
	   {
         check->rezult+= write(1, str++, 1);
	   }
      else
	  {
		if (*++str == '-')	//Проверка флаги
		{
			check->flag = check->flag | F_MINS;
			check->rezult++;
			str++;
		}
		if (*str == '0')
		{
			check->flag = check->flag | F_ZERO;
			if(check->flag & F_MINS)
				check->flag = F_MINS;	//Проверить работу условия, что если есть минус, то 0 игнорируется!
			check->rezult++;
			str++;
		}
		if (*str == '*')	//Проверка ширину указанную в списке аргументов
			check->width = va_arg(ap, int);
			while ('0' <= *str && *str <= '9') //Проверяем на числовое значение ширины. Вероятно надо использовать итоа!
			{
				check->width = check->width * 10 + (*str - '0');
				check->rezult++;
				str++;
			}
				if (*str == '.')	//Проверка точности
		{
			if(*++str == '*' || ('0' <= *str && *str <= '9'))	//Если следующее значение * или цифра, то точность есть!
			{
				check->flag= check->flag | F_DOT;
				if (*str == '*') //Проверка точность указанную в списке аргументов
				{
					check->precision = va_arg(ap, int);
					check->rezult++;
					str++;
				}
				// else
				while ('0' <= *str && *str <= '9') //Проверяем на числовое значение точности
					{
						check->precision = check->precision * 10 + (*str - '0');
						check->rezult++;
						str++;
					}
			}	
			check->rezult++;
		}
		if (*str == 's')
		{
			ft_printf_s(va_arg(ap, char *), check);
			str++;
		}
	}
   }
   va_end(ap);
   return (check->rezult);
}

int main()
{
	printf("test1 text%-10.5s\n", "1234567890");
	printf("test2 text%10.5s\n", "1234567890");
	ft_printf("test3 text%-10.5s\n", "1234567890");
	ft_printf("test4 text%10.5s\n", "1234567");
   return (0);
}
