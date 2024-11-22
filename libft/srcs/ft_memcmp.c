/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:20:51 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:12 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* compare deux blocs de memoires
tant qu'on arrive pas a 'n'
si p1 et p2 sont differents on return la difference */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char buf1[] = {0x01, 0x02, 0x03};
	char buf2[] = {0x01, 0x02, 0x03};

	int	result = ft_memcmp(buf1, buf2, 3);

	if (result == 0)
		printf("memoire egale");
	else if (result < 0)
		printf("buf1 inf a buf2");
	else
		printf("buf1 sup a buf2");
} */
