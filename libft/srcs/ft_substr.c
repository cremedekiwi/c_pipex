/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:30:03 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:42:20 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* return une substr
si start est >= a la len de s, on return une chaine vide
si la len est > a la difference de la len de s et start return cette dif
on copie dans *substr la sous chaine qu'on veut grace a l'index start */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int main(void)
{
	char	*s = "Hello, World !";
	char	*substr;

	// normal case
	substr = ft_substr(s, 7, 5);
	printf("%s\n", substr);
	free(substr);

	// start index is out of bonds
	substr = ft_substr(s, 20, 5);
	printf("%s\n", substr);
	free(substr);

	// len is greater than (source len - start index)
	substr = ft_substr(s, 7, 20);
	printf("%s\n", substr);
	free(substr);

	// source is NULL
	substr = ft_substr(NULL, 0, 5);
	printf("%s\n", substr);
	free(substr);

	return(0);
} */
