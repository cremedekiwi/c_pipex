/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:59:49 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:15 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* si dest et src est false, return false
tant que 'n' existe on copie s dans d, et on incemente, d et s
et on decremente n pour sortir de la boucle */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
/*
int	main(void)
{
	char dest1[20] = "Original String";
	const char src1[20] = "New String";
	char *result1 = ft_memcpy(dest1, src1, 10);
	printf("%s\n", result1);

	char *result2 = ft_memcpy(((void*)0), "segfaulter tu dois", 17);
	printf("%s\n", result2);

	char *result3 = ft_memcpy("            ", ((void*)0), 17);
	printf("%s\n", result3);

	char dest4[20] = "Same Memory";
	char *result4 = ft_memcpy(dest4, dest4, 11);
	printf("%s\n", result4);

	char dest5[20] = "Non-empty";
	const char src5[20] = "Source";
	char *result5 = ft_memcpy(dest5, src5, 0);
	printf("%s\n", result5);

	char dest6[20] = "Axxxxxxxxxxxxxx";
	const char src6[20] = "Source String";
	char *result6 = ft_memcpy(dest6, src6, 13);
	printf("%s\n", result6);

	return (0);
} */
