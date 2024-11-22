/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:01:51 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:22 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* deplace de 1 char c */
/* static char	ft_increment(unsigned int i, char c)
{
	i = 0;
	return (c + 1);
} */

/*  applique 'f' a chaque char de 's'
protege si NULL
malloc de len de s + 1, verifie si malloc fail */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main(void)
{
    char const *s = "Hello, World!";
    char *result = ft_strmapi(s, ft_increment);

    if (result != NULL)
    {
        printf("%s\n", result);
        free(result);
    }
    return 0;
} */
