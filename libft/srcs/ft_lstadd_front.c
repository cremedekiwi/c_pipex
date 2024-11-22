/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:07:41 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:45 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* ajoute un nouvel element au debut de la liste chainee
si new est null pas de nouvel element a ajouter
si la liste est null, c'est quel est vide, alors new devient le premier element
si liste non vide, on ajoute new au debut de la liste
new->next = *lst pointe vers l'ancien premier element de la liste
*lst = new update *lst pour qu'il pointe vers new (nouveau premier element) */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*head = NULL;
	t_list	*node1 = (t_list *)malloc(sizeof(t_list));
	t_list	*node2 = (t_list *)malloc(sizeof(t_list));

	if (!node1 || !node2)
		return (1);
	node1->content = "Kebab";
	node1->next = NULL;

	node2->content = "Pizza";
	node2->next = NULL;

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	printf("%s\n", (char *)(node1->content));
	printf("%s\n", (char *)(node2->content));

	free(node1);
	free(node2);

	return(0);
} */
