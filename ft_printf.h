/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:37:24 by feschall          #+#    #+#             */
/*   Updated: 2021/03/06 14:06:03 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> // Delete!
# include <stdarg.h>
# include <unistd.h>

# define F_NULL	0b00000000
# define F_MINS	0b00000001
# define F_ZERO	0b00000010
# define F_DOT	0b00000100
// # define F_LJST 0b00001000 //left justified - выравнивания по левому краю
# define F_ZFIL 0b00010000 // zero filled - Заполнение левый край нулями

typedef struct s_struct
{
	unsigned int	rezult;
	unsigned char	flag;
    unsigned int	len_tmp;
	int				i;
    int 			len_str;
	int				width; // Минимальная ширина
	int				precision;
	char			ch_p; //check protection ' 'or '0'
}				t_struct;

int ft_strlen(const char *s);
int ft_putstr(const char *str, int len, t_struct *ts);
void reset_f_v(t_struct *ts);
void check_flag(const char *str, t_struct *ts);
void check_width(const char *str, va_list ap, t_struct *ts);
void check_precision(const char *str, va_list ap, t_struct *ts);
int check_type(const char *str, va_list ap, t_struct *ts);
int	output_type_s(const char *str, t_struct *ts);
void output_type_c(int c, t_struct *ts);

#endif
