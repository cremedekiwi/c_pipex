/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:03:58 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:57 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* cherche la premiere occurence de *s
tant que *s est non null et que *s != c, on avance
si *s == c on return s */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while ((*s != '\0') && (*s != uc))
		s++;
	if (*s == uc)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char* s = "kiwi";
	int	c = 'i';
	char *result = ft_strchr(s, c);
	//char *result = ft_strchr(s, 't' + 256);
	//char *result = ft_strchr("teste", 'e');


	if (result != NULL)
		printf("'%c' found at position %ld\n", c, result - s);
	else
		printf("'%c' not found\n", c);
} */
