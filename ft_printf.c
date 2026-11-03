/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisilva <tisilva@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:43:11 by tisilva           #+#    #+#             */
/*   Updated: 2026/11/03 09:46:24 by tisilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putbase(unsigned long n, char *base, t_base_len len,
		t_base_type type)
{
	int	count;

	count = 0;
	if (type == NEG)
	{
		count += write(1, "-", 1);
		n = (unsigned long)-(long)n;
	}
	if (type == PTR)
	{
		if (n == 0)
			return (write(1, "(nil)", 5));
		count += write(1, "0x", 2);
	}
	if (n >= (unsigned long)len)
		count += putbase(n / len, base, len, UNS);
	write(1, &base[n % len], 1);
	return (count + 1);
}

static int	put_text(char c, va_list *args)
{
	char	*str;
	int		len;

	if (c == CHAR)
		return (write(1, &(char){va_arg(*args, int)}, 1));
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

static int	put_format(char c, va_list *args)
{
	int	n;

	if (c == CHAR || c == STRING)
		return (put_text(c, args));
	if (c == DEC || c == INTEGER)
	{
		n = va_arg(*args, int);
		if (n < 0)
			return (putbase((unsigned long)n, DEC_BASE, DEC_LEN, NEG));
		return (putbase(n, DEC_BASE, DEC_LEN, UNS));
	}
	if (c == POINTER)
		return (putbase((unsigned long)va_arg(*args, void *),
				HEX_LBASE, HEX_LEN, PTR));
	if (c == UNSIGNED)
		return (putbase(va_arg(*args, unsigned int), DEC_BASE, DEC_LEN, UNS));
	if (c == HEX_LOWER)
		return (putbase(va_arg(*args, unsigned int), HEX_LBASE, HEX_LEN, UNS));
	if (c == HEX_UPPER)
		return (putbase(va_arg(*args, unsigned int), HEX_UBASE, HEX_LEN, UNS));
	return (write(1, "%", 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format || write(1, NULL, 0) == -1)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += put_format(*format, &args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
