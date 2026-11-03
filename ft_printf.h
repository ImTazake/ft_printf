/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisilva <tisilva@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:43:24 by tisilva           #+#    #+#             */
/*   Updated: 2026/11/03 10:43:43 by tisilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

# define DEC_BASE  "0123456789"
# define HEX_UBASE "0123456789ABCDEF"
# define HEX_LBASE "0123456789abcdef"

typedef enum e_base_type
{
	UNS,
	PTR,
	NEG
}	t_base_type;

typedef enum e_base_len
{
	DEC_LEN = 10,
	HEX_LEN = 16
}	t_base_len;

typedef enum e_format
{
	CHAR = 'c',
	STRING = 's',
	POINTER = 'p',
	DEC = 'd',
	INTEGER = 'i',
	UNSIGNED = 'u',
	HEX_LOWER = 'x',
	HEX_UPPER = 'X',
	PERCENT = '%'
}	t_format;

int	ft_printf(const char *format, ...);

#endif