/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:08:07 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:11 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* concatene src dans dest
on a besoin de la len de dst et de src
si dst_size est <= a dst_len, pas assez d'espace
donc on aggrandi en return (dst_size + src_len)
cpy_len est le nb de char a copier dst_size - dst_len - 1
si ce nb est plus grand que la len de la src on copie sa len
copie cpy_len char de src a la fin de dst et on ajoute '\0' */
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cpy_len;

	if (!dst && !dst_size)
		return (dst_size);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if ((dst_size == 0) || dst_size <= dst_len)
		return (dst_size + src_len);
	cpy_len = dst_size - dst_len - 1;
	if (cpy_len > src_len)
		cpy_len = src_len;
	ft_memcpy(dst + dst_len, src, cpy_len);
	dst[dst_len + cpy_len] = '\0';
	return (dst_len + src_len);
}
/*
int main(void)
{
	char	buffer[20] = "Hello, ";
	const char	*to_append = "world!";

	size_t buffer_size = sizeof(buffer);
	size_t result = ft_strlcat(buffer, to_append, buffer_size);

	printf("Result : %s\n", buffer);
	printf("Total length : %zu", result);

	return (0);
} */
