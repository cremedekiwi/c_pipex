/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:38:34 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:03 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
void	ft_print_index_and_char(unsigned int i, char *c)
{
	printf("Index %u, char is %c\n", i, *c);
} */

/* si s ou f NULL arrete le program
tant que s existe, on applique f sur chaque char avec s en argument */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "Hey";

	ft_striteri(str, ft_print_index_and_char);
	return (0);
} */
