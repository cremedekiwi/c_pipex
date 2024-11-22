/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:14:53 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:51 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* appelle del pour supprimer content et free lst */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	if(!node)
		return(1);
	node->content = malloc(100);
	if (!(node->content))
	{
		free(node);
		return (1);
	}
	node->next = NULL;

    printf("Before deletion:\n");
    printf("Node address: %p\n", (void*)node);
    printf("Node content address: %p\n", node->content);
    printf("Node next address: %p\n\n", (void*)node->next);

    ft_lstdelone(node, free);

    printf("After deletion:\n");
    printf("Node address: %p\n", (void*)node);
	printf("Node content address: %p\n", node->content);
	printf("Node next address: %p\n", (void*)node->next);

    return (0);
} */
