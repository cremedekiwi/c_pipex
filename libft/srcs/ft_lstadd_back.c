/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:06:51 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:42 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* ajoute un element a la fin de la liste chainee
si *lst est null, place new comme premier et seul element
si non vide, stock le dernier element dans last
ajoute le nouvel element en dernier */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
int	main(void)
{
	t_list	*list = NULL;
	t_list	*last = NULL;
	t_list	node1 = { .content = "Hello", .next = NULL };
	t_list	node2 = { .content = "World", .next = NULL };

	ft_lstadd_back(&list, &node1);
	ft_lstadd_back(&list, &node2);

	last = ft_lstlast(list);
	if (last != NULL)
		printf("%s\n", (char *)last->content);
} */
