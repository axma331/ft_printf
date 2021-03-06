/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:37:24 by feschall          #+#    #+#             */
/*   Updated: 2021/03/06 09:15:01 by feschall         ###   ########.fr       */
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
// # define F_LSID 0b00001000 //left side - выравнивания по левому краю
# define F_SORZ 0b00010000 // spase or zero

typedef struct s_struct
{
	unsigned int	rezult;
	unsigned char	flag;
    unsigned int	len_tmp;
	int				i;
    int 			len_str;
	int				width;
	int				precision;
	char			type;
}				t_struct;

typedef struct s_type
{
	char			c;
	char			*s;
	unsigned char	uc;
	int				i;
	unsigned int	ui;
	unsigned long	ul;
}				t_type;

int ft_strlen(const char *s);
int ft_putstr(const char *str, int len, t_struct *ts);
void reset_f_v(t_struct *ts);
void check_flag(const char *str, t_struct *ts);
void check_width(const char *str, va_list ap, t_struct *ts);
void check_precision(const char *str, va_list ap, t_struct *ts);
void check_type(const char *str, t_struct *ts);
void output_type_s(const char *str, t_struct *ts);

#endif
