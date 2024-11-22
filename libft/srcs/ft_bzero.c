/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:36:11 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:20 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* init toutes les valeurs a 0 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
/*
int	main(void)
{
	char	buffer[4] = "test";

	ft_bzero(buffer, 4);
	int	i = 0;
	while (i < 4)
	{
		printf("%d", buffer[i]);
		i++;
	}
	printf("\n");

	return (0);
} */
