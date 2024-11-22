/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:00:52 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:28 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* trouve little dans big et renvoie le ptr
si little == '\0' return big
tant que *big existe et len est >= a la len de little
si strncmp == 0, on a un match et on return big */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	while (*big != '\0' && len >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*str = "Hello, world!";
	const char	*substr = "world";
	char		*result = ft_strnstr(str, substr, ft_strlen(str));

	if (result != NULL)
		printf("Found at position: %ld || %s\n", result - str, result);
	else
		printf("Not found\n");
	return (0);
} */
