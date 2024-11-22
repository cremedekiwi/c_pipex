/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:22:42 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:48 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* Imprime un nombre sur fd
si int min return la valeur
si negative ecrit '-', et n = - n
si plus d'un chiffre, (n / 10) elimine le dernier chiffre
ecrit les chiffres de gauche a droite
(n % 10) pour le dernier chiffre
c = n + '0' ; converti en sa valeur ascii */
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			c = n + '0';
			write(fd, &c, 1);
		}
	}
}
/*
int main(void)
{
	ft_putnbr_fd(42, 1);
	return (42);
} */
