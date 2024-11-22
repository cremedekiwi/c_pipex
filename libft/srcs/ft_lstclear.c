/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:32:01 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/19 17:32:48 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* parcours la liste chaine et supprime chaque node */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
/*
void	del(void *content)
{
	free(content);
}

void	print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	head = malloc(sizeof(t_list));
	head->content = malloc(sizeof(int));
	*(int *)head->content = 1;
	second = malloc(sizeof(t_list));
	second->content = malloc(sizeof(int));
	*(int *)second->content = 2;
	head->next = second;
	third = malloc(sizeof(t_list));
	third->content = malloc(sizeof(int));
	*(int *)third->content = 3;
	second->next = third;
	third->next = NULL;
	printf("Before clearing the list: ");
	print_list(head);
	ft_lstclear(&head, del);
	printf("After clearing the list: ");
	print_list(head);
	return (0);
} */
