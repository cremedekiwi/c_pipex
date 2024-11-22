/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:24:24 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:03 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* cree un nouveau node dans une liste chainee
si node est non null, alloc reussi
node->content = content affecte le contenu en param dans content du new node
node->next = NULL init le champ next du node a NULL (dernier node) */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}
/*
int	main(void)
{
	int	*p = malloc(sizeof(int));
	*p = 5;

	t_list *node = ft_lstnew(p);
	if (node != NULL)
		printf("%d\n", *(int *)(node->content));
	else
		printf("ko\n");
	free(p);
	free(node);
	return (0);
} */
