/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:00 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:15 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* cpy str
si size 0, on retourne la len de src
tant qu'on arrive avant size - 1 et que *src existe
on copie dans *dst = *src
on rajoute le char null a la fin */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		src_len;
	size_t		i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	char dst[10];
	const char *src = "Hello, World!";
	size_t cpy_len = ft_strlcpy(dst, src, sizeof(dst));

	printf("Copied string : %s\n", dst);
	printf("Total length of source : %zu\n", cpy_len);

	return(0);
} */
