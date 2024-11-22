/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:52 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:34 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* on copie de gauche a droite */
static void	ft_memmove_forward(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

/* on copie de droite a gauche */
static void	ft_memmove_backward(char *dest, const char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
}

/* si dest et src sont null on return null
si dest est avant src on copie vers l'avant
sinon on copie vers l'arriere */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
		ft_memmove_forward(d, s, n);
	else
		ft_memmove_backward(d, s, n);
	return (dest);
}
/*
int	main (void)
{
	char str1[] = "Hello, World!";
    ft_memmove(str1 + 7, str1, 6);
    printf("d < s : %s\n", str1);

	char str2[] = "Hello, World!";
	ft_memmove(str2, str2 + 7, 6);
	printf("d > s : %s\n", str2);

	return (0);
} */
