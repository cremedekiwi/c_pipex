/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:18:36 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:33:06 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* compte le nb d'elements dans une liste
on utilise *temp pour ne pas modifier *lst
tant que temp existe, on passe au next node temp->next et on incremente i */
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
/*
t_list	*newNode(int data)
{
	t_list *node = (t_list*)malloc(sizeof(t_list));
	int	*ptr = malloc(sizeof(int));
	*ptr = data;
	node->content = ptr;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);

	printf("len : %d\n", ft_lstsize(head));

	return (0);
} */
