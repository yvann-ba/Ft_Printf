/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:09:51 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/20 16:42:55 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(const char *format, va_list args)
{
	int		len;

	len = 0;
	if (*format == 'c')
		len = ft_putlchar(va_arg(args, int));
	else if (*format == 's')
		len = ft_putlstr(va_arg(args, char *));
	else if (*format == 'p')
		len = ft_display_adress(va_arg(args, unsigned long));
	else if (*format == 'd' || *format == 'i')
		len = ft_putlnbr_base(va_arg(args, int), "0123456789");
	else if (*format == 'u')
		len = ft_putlnbr_ubase(va_arg(args, unsigned int), "0123456789");
	else if (*format == 'x')
		len = ft_putlnbr_ubase(va_arg(args, int), "0123456789abcdef");
	else if (*format == 'X')
		len = ft_putlnbr_ubase(va_arg(args, int), "0123456789ABCDEF");
	else if (*format == '%')
	{
		write(1, "%", 1);
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start (args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			i += check_format(format, args);
			format++;
		}
		else
		{
			write(1, format, 1);
			i++;
			format++;
		}
	}
	va_end(args);
	return (i);
}
