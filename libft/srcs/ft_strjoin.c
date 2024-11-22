/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:47 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:06 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* result : malloc de len de s1 + s2 + 1, on protege
et on utilise memcpy pour copier s1 dans result
puis on reutilise pour copier s2 a la suite (result + len_s1) */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(len_s1 + len_s2 + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len_s1);
	ft_memcpy(result + len_s1, s2, len_s2 + 1);
	return (result);
}
/*
int	main(void)
{
	char	*s1 = "Hello, ";
	char	*s2 = "World!";
	char	*joined_str = ft_strjoin(s1, s2);

	if (joined_str)
	{
		printf("%s\n", joined_str);
		free(joined_str);
	}
	return (0);
} */
