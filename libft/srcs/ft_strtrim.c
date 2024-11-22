/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:44:41 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:34 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* supprime 'set' dans 's1' au debut et a la fin
start et end ptrs sont init pour pointer au debut et a la fin de s1
start++ jusqu'a que le char de set est trouve dans s1
end-- backwards tant que le char de set est trouve dans s1
len : difference entre end et start | len de la string trim
result : memoire de la taile de len + 1
strlcpy : copie la string trim de s1 (de start a end) dans res */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*result;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;
	len = end - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, start, len + 1);
	return (result);
}
/*
int	main(void)
{
	char const	*s1 = "   Hello, World!   ";
	char const *set = " ";
	char *trimmed = ft_strtrim(s1, set);

	if (trimmed)
	{
		printf("Original: '%s'\n", s1);
		printf("Trimmed: '%s'\n", trimmed);
		free(trimmed);
	}
	else
		printf("malloc failled\n");

	return (0);
} */
