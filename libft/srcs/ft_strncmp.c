/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:05:18 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:25 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* on compare jusqu'a 'n' octet
si s1 ou s2 NULL return *s1 - *s2
des que *s1 et *s2 sont differents return la difference */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char s1[] = "Lea";
	char s2[] = "Leane";

	int result = ft_strncmp(s1, s2, 3);

	if (result < 0)
		printf("s1 is less than s2");
	else if (result > 0)
		printf("s1 is greater than s2");
	else
		printf("s1 is equal than s2");

	return (0);
} */
