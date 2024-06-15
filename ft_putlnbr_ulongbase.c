/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_ulongbase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:24:09 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/20 16:33:30 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_long_nbr(unsigned long nbr, char *base)
{
	unsigned int	i;
	unsigned int	digit;
	unsigned int	counter;

	i = 0;
	counter = 0;
	while (base[i])
		i++;
	digit = nbr % i;
	nbr = nbr / i;
	if (nbr)
		counter += ft_unsigned_long_nbr(nbr, base);
	write(1, &base[digit], 1);
	counter++;
	return (counter);
}

unsigned int	ft_putlnbr_ulongbase(unsigned long nbr, char *base)
{
	unsigned int	counter;

	counter = 0;
	if (ft_check_parameters(base) && ft_check_character_occurence(base))
		counter += ft_unsigned_long_nbr(nbr, base);
	return (counter);
}
