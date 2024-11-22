/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:19:19 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:22 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* calloc permet de malloc puis de mettre chaque case a 0
tant que i n'arrive pas a la taille total, il met chaque char_ptr[i] a 0 */
void	*ft_calloc(size_t nb_elements, size_t size)
{
	size_t	total_size;
	size_t	i;
	void	*ptr;
	char	*char_ptr;

	total_size = nb_elements * size;
	i = 0;
	ptr = malloc(total_size);
	char_ptr = (char *)ptr;
	if (ptr == NULL)
		return (NULL);
	while (i < total_size)
	{
		char_ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int main(void)
{
	size_t	nb_elements = 3;
	size_t	size = sizeof(int);
	size_t	i = 0;

	int	*array = (int *)ft_calloc(nb_elements, size);
	if (array == NULL)
	{
		printf("Failed");
		return (1);
	}
	printf("Allocated\n");
	while (i < nb_elements)
	{
		printf("array[%zu] = %d\n", i, array[i]);
		i++;
	}
	free(array);
	return(0);
} */
