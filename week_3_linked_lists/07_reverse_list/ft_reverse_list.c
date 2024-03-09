/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:00:56 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/10 01:31:49 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

t_list	*ft_reverse_list(t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	while (lst != NULL)
	{
		next = lst->next;
		lst->next = prev;
		prev = lst;
		lst = next;
	}
	return (prev);
}

/*
int	main(void)
{
	t_list	lst1[] = {
	{.content = 1, .next = &lst1[1]},
	{.content = 2, .next = &lst1[2]},
	{.content = 3, .next = NULL}
	};
	t_list	lst2[] = {
	{.content = 7, .next = &lst2[1]},
	{.content = 15, .next = &lst2[2]},
	{.content = 9, .next = &lst2[3]},
	{.content = 2, .next = NULL}
	};
	t_list	lst3[] = {
	{.content = 1, .next = NULL},
	};
	t_list	*result;
	t_list	*head;

	head = lst1;
	printf("Original List: ");
	while (head != NULL)
	{
		printf("%d->", head->content);
		head = head->next;
	}
	printf("NULL\nReversed List: ");
	result = ft_reverse_list(lst1);
	while (result != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("NULL\n\n");
	head = lst2;
	printf("Original List: ");
	while (head != NULL)
	{
		printf("%d->", head->content);
		head = head->next;
	}
	printf("NULL\nReversed List: ");
	result = ft_reverse_list(lst2);
	while (result != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("NULL\n\n");
	head = lst3;
	printf("Original List: ");
	while (head != NULL)
	{
		printf("%d->", head->content);
		head = head->next;
	}
	printf("NULL\nReversed List: ");
	result = ft_reverse_list(lst3);
	while (result != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("NULL\n");
	return (0);
}
*/
