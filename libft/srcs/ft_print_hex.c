/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:37:08 by jarumuga          #+#    #+#             */
/*   Updated: 2024/06/05 12:22:58 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* uppercase is a flag : true or false
if true hex_digits is uppercasem if false it's lowercase
buffer is 8 digits + 1 for null
i init at 7 because we add digits from the end
until i is -1 or n == 0, copy in buffer hex_digits[n % 16]
n /= 16 to shift out the processed digit
add null to the end of the buffer */
int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*hex_digits;
	char	buffer[9];
	int		i;
	int		count;

	i = 7;
	count = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	while (i >= 0)
	{
		buffer[i] = hex_digits[n % 16];
		n /= 16;
		count++;
		if (n == 0)
			break ;
		i--;
	}
	buffer[8] = '\0';
	return (ft_print_str(&buffer[8 - count]));
}
