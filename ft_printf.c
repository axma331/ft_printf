/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:34:09 by feschall          #+#    #+#             */
/*   Updated: 2021/03/04 14:04:00 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int ft_strlen(const char *s)
{
   int len;

   len = 0;
   while(*s++ != '\0')
      len++;
   return (len);
}

int ft_printf(const char *str, ...)
{
	t_struct *check;
	
	check->rezult = 0;
	check->flag = F_NULL;
	check->width = 0;
	check->dot = 0;
	check->len_s = 0;

   va_list ap;
   va_start(ap, str);
   while(*str != '\0')
   {
	   if (!(*str == '%'))
	   {
         check->rezult+= write(1, str++, 1);
		 check->len_s ++;
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
				check->flag = F_ZERO;	//Проверить работу условия, что если есть минус, то 0 игнорируется!
			check->rezult++;
			str++;
		}
		if (*str == '*')	//Проверка ширину указанную в списке аргументов
			check->width = va_arg(ap, int);
		// else
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
					check->dot = va_arg(ap, int);
					check->rezult++;
					str++;
				}
				// else
				while ('0' <= *str && *str <= '9') //Проверяем на числовое значение точности
					{
						check->dot = check->dot * 10 + (*str - '0');
						check->rezult++;
						str++;
					}
			}	
			check->rezult++;
		}
		if (*str == 's' || *str == 'p' || *str == 'd' || *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X')	//Проверка типов
		{
			str++;
		}
	  }

   }
   va_end(ap);

   printf("1 %u\n", check->rezult);
   printf("2 %d\n", check->flag);
   printf("3 %c\n", check->type);
   printf("4 %d\n", check->dot);
   
   return (check->rezult);
}

int main()
{
	printf("test2 text%-012.9s\n");
	ft_printf("test2 text%-012.9s\n");
   return (0);
}
