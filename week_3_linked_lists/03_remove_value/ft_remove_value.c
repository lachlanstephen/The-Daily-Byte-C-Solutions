/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 03:10:17 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/05 03:53:19 by darkwater        ###   ########.fr       */
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

t_list	*ft_remove_value(t_list *lst, int val)
{
	t_list	*head;
	t_list	*prev;

	while (lst != NULL && lst->content == val)
		lst = lst->next;
	head = lst;
	prev = lst;
	while (lst != NULL)
	{
		if (lst->content == val)
		{
			while (lst != NULL && lst->content == val)
				lst = lst->next;
			prev->next = lst;
			continue ;
		}
		prev = lst;
		lst = lst->next;
	}
	return (head);
}

/*
int	main(void)
{
	int		val;
	t_list	lst1[] = {
	{.content = 1, .next = &lst1[1]},
	{.content = 2, .next = &lst1[2]},
	{.content = 3, .next = NULL}
	};
	t_list	lst2[] = {
	{.content = 8, .next = &lst2[1]},
	{.content = 1, .next = &lst2[2]},
	{.content = 1, .next = &lst2[3]},
	{.content = 4, .next = &lst2[4]},
	{.content = 12, .next = NULL}
	};
	t_list	lst3[] = {
	{.content = 7, .next = &lst3[1]},
	{.content = 12, .next = &lst3[2]},
	{.content = 2, .next = &lst3[3]},
	{.content = 9, .next = NULL}
	};
	t_list	*result;

	val = 3;
	result = ft_remove_value(lst1, val);
	while (result->next != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("%d->NULL\n", result->content);
	val = 1;
	result = ft_remove_value(lst2, val);
	while (result->next != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("%d->NULL\n", result->content);
	val = 7;
	result = ft_remove_value(lst3, val);
	while (result->next != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("%d->NULL\n", result->content);
	return (0);
}
*/
