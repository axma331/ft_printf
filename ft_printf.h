/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:37:24 by feschall          #+#    #+#             */
/*   Updated: 2021/03/12 06:14:52 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define F_NUL	0b00000000
# define F_MIN	0b00000001
# define F_ZRO	0b00000010
# define F_DOT	0b00000100

typedef struct		s_struct
{
	char			*str_n;
	unsigned char	flag;
	int				neg;
	int				i;
	int				len_t;
	int				len_s;
	int				width;
	int				prcs;
	int				dev;
	int				ca;
	unsigned int	result;
}					t_struct;

char				*ft_litoa_b(long int n, t_struct *ts);
int					count_b(long int n, t_struct *ts);
int					ft_strlen(const char *s);
int					ft_putstr(const char *str, int len, t_struct *ts);
void				reset_f_v(t_struct *ts);
void				check_flag_width(const char *str, va_list ap, t_struct *ts);
void				check_precision(const char *str, va_list ap, t_struct *ts);
void				check_f_w_p(const char *str, va_list ap, t_struct *ts);
void				check_type(const char *str, va_list ap, t_struct *ts);
void				output_type_c(int c, t_struct *ts);
void				output_type_s(const char *str, t_struct *ts);
void				output_type_u(unsigned int n, t_struct *ts);
void				output_type_di(int n, t_struct *ts);
void				output_type_di_lt(t_struct *ts);
void				output_type_x(unsigned int n, t_struct *ts);
void				output_type_p(unsigned long n, t_struct *ts);
void				output_type_per(t_struct *ts);

#endif
