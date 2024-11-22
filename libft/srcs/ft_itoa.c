/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:14:02 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:39 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* compte le nombre de chiffre dans un nombre
digit : si n = 0, digit = 1 ; si n = 42 par exemple, digit = 1 a l'init
tant que 'n' existe on divise par 10 pour enlever le dernier chiffre
et on incremente le nombre de digit */
static int	digit_count(int n)
{
	int	digit;

	digit = !n;
	while (n)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

/* int to ascii

sign : si n est negative, sign = 1 sinon 0
len : nombre de chiffre + sign (1 si negative)
result : alloue la memoire -> 'len' + '\0', puis protege si null
	si 'n' est neg, premier char '-'
	-(n % 10) + '0' pour le reste (le dernier chiffre) est le converti en ascii
	(n / 10) elimine le dernier chiffre pour la prochaine iteration
	(n = -(n / 10)) rend le resultat positif */
char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*result;

	sign = n < 0;
	len = digit_count(n) + sign;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (result);
	result[len] = 0;
	if (sign)
	{
		*result = '-';
		len--;
		result[len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len - sign)
	{
		len--;
		result[len] = n % 10 + '0';
		n = n / 10;
	}
	return (result);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(42));
	return (0);
} */
