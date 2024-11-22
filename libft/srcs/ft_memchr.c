/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:38:59 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:09 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* search la premiere occurence d'un char
tant qu'on arrive pas a n
si on trouve le char on return le *p */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s = "Kiwi";
	char		c = 'w';
	size_t		len = sizeof(s);

	char *result = ft_memchr(s, c, len);

	if (result != NULL)
		printf("'%c' find at index %ld\n", c, result - s);
	else
		printf("'%c' not find", c);
	return (0);
} */
