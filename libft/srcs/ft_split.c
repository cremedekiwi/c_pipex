/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:58 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:54 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* duplique 'n' char of string 's'
return dup qui a ete malloc */
static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	if (s == NULL)
		return (NULL);
	dup = malloc(n + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, n + 1);
	return (dup);
}

/* alloue de la memoire pour un mot
si array est null, free chaque case du tableau puis array */
static int	ft_walloc(char **array_words, const char *s, size_t len, int i)
{
	array_words[i] = ft_strndup(s, len);
	if (array_words[i] == NULL)
	{
		while (i > 0)
			free(array_words[--i]);
		free(array_words);
		return (1);
	}
	return (0);
}

/* rempli le tableau avec les mots extraits de 's' et delimite par 'c'
si on atteint un delimiteur on avance *s et la len
tant que len existe on alloue la memoire pour le mot */
static int	ft_fill(char **array_words, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		len = 0;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (ft_walloc(array_words, s - len, len, i))
				return (1);
			i++;
		}
	}
	return (0);
}

/* compte le nombre de mots dans 's' delimite par 'c'
words est un compteur de mot
is_word nous permet de savoir si on est dans un mot ou non
si on atteint un delimiteur ce n'est pas un mot
sinon si is_word = 0, on le change a 1 et on augmente words */
static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	int		is_word;

	words = 0;
	is_word = 0;
	while (*s)
	{
		if (*s == c)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			words++;
		}
		s++;
	}
	return (words);
}

/* divise 's' dans un tableau de mots en utilisant le delimiter 'c'
words contient le nombre de mot
si ft_fill est true c'est que la memoire a bien ete alloue */
char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**array_words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	array_words = (char **)malloc((words + 1) * sizeof(char *));
	if (array_words == NULL)
		return (NULL);
	array_words[words] = NULL;
	if (ft_fill(array_words, s, c))
		return (NULL);
	return (array_words);
}

/*
int	main()
{
	int	i;

	i = 0;
	char **result1 = ft_split("hello world", ' ');
	while (result1[i] != NULL)
	{
		printf("'%s'\n", result1[i]);
		free(result1[i]);
		i++;
	}

	free(result1);

	i = 0;
	char **result2 = ft_split("   ", ' ');
	while (result2[i] != NULL)
	{
		printf("'%s'\n", result2[i]);
		free(result2[i]);
		i++;
	}
	free(result2);

	i = 0;
	char **result3 = ft_split("word", ' ');
	while (result3[i] != NULL)
	{
		printf("'%s'\n", result3[i]);
		free(result3[i]);
		i++;
	}
	free(result3);
} */
