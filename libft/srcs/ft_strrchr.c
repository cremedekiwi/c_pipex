/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:37:46 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:31 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* cherche la derniere occurence de *s
tant que *s est non null si *s == c, last_o = s
last_o change de valeur jusqu'a la derniere occurence c */
char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*last_o;

	uc = (unsigned char)c;
	last_o = NULL;
	while (*s != '\0')
	{
		if (*s == uc)
			last_o = (char *)s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (last_o);
}
/*
int	main(void)
{
	const char* s = "kiwi";
	char	c = 'i';

	char *result1 = ft_strrchr(s, c);
	char *result2 = strrchr(s, c);
	if (result1 != NULL || result2 != NULL)
	{
		printf("ft_strrchr : '%c' found at position %ld\n", c, result1 - s);
		printf("strrchr : '%c' found at position %ld\n", c, result2 - s);
	}
	else
		printf("'%c' not found\n", c);
	return (0);
} */
