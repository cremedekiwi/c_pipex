/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:20:54 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/26 14:23:34 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* return true si espace ou tab */
static int	ft_is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

/* ascii to int
si is_space est true, on avance la str
si on croise un + ou un - puis si c'est un moins, on change le sign a (-1)
si c'est un chiffre, on affecte (*str - '0') pour changer en entier
et on multiplie par 10 pour passer au chiffre suivant de droite */
long long	ft_atoi(const char *str)
{
	long long	result;
	long long	sign;

	result = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char	str[] = "-42";

	printf("%d", ft_atoi(str));
	return (0);
} */
