/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:46 by jarumuga          #+#    #+#             */
/*   Updated: 2024/06/07 07:59:59 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* prints in a specified base
if nbr >= base_len
need to be broken down with nbr / base_len
print the char corresponding to 'nbr' in the base */
static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= (unsigned long)base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
		count += ft_putnbr_base(nbr % base_len, base);
	}
	else
	{
		ft_print_char(base[nbr]);
		count++;
	}
	return (count);
}

/* init count to 0
if ptr is NULL, print "(nil)"
print prefix "0x"
print hexadecimal address */
int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_print_str("(nil)");
		return (count);
	}
	count += ft_print_str("0x");
	count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
