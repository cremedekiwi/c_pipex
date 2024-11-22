/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:13:47 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:00 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* duplique une string
on malloc de la len de s + 1, on protege
tant que s non null, on copie dans array = *s
on rajoute le char NULL */
char	*ft_strdup(const char *s)
{
	char	*array;
	int		i;

	i = 0;
	array = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!array)
		return (NULL);
	while (*s)
	{
		array[i] = *s;
		i++;
		s++;
	}
	array[i] = '\0';
	return (array);
}
/*
int	main(void)
{
	char	array[4] = "abc";
	printf("%s", ft_strdup(array));
} */
