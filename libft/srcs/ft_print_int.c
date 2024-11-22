/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:45:21 by jarumuga          #+#    #+#             */
/*   Updated: 2024/06/05 14:24:07 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* check if int min
check if negative
if number is greater than 9, you divise by 10
you print one digit at a time */
int	ft_print_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_print_str("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_print_int(n / 10);
	ft_print_char((n % 10) + '0');
	count++;
	return (count);
}
