/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:43 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/20 16:25:35 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putlstr(const char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_display_adress(unsigned long ptr)
{
	int	counter;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	counter = 0;
	write(1, "0x", 2);
	counter += 2;
	counter += ft_putlnbr_ulongbase(ptr, "0123456789abcdef");
	return (counter);
}
