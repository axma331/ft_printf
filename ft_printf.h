/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:37:24 by feschall          #+#    #+#             */
/*   Updated: 2021/03/04 21:40:56 by feschall         ###   ########.fr       */
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

typedef struct s_struct
{
    int 			len_s;
	unsigned int	rezult;
	unsigned char	flag;
	int				width;
	int				precision;
	char			type;
}				t_struct;

#endif
