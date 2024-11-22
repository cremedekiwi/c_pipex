/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:26:34 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:57 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* renvoi le dernier element de la liste chainee
si lst est vide, on return null
tant que lst->next n'est pas null
on met a jour lst pour qu'il point pointe vers le next node
des que !(lst->next), on pointe vers le dernier element non null */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	node1, node2, node3;
	int	val1 = 1, val2 = 2, val3 = 3;

	node1.content = &val1;
	node2.content = &val2;
	node3.content = &val3;

	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;

	t_list	*last = ft_lstlast(&node1);

	if (last != NULL)
		printf("%d\n", *(int*)last->content);
	else
		printf("ko");
	return (0);
} */
