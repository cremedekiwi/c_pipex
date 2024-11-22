/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:39:14 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:40 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* tant que n existe, on copie dans *str = c */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[42] = "Hello, World!";
	printf("%s\n", str);
	ft_memset(str + 7, 'X', 5);
	printf("%s\n", str);
} */
