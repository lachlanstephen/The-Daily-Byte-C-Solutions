/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_middle_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:52:36 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/06 23:31:24 by darkwater        ###   ########.fr       */
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

t_list	*ft_find_middle(t_list *lst)
{
	int		count;
	int		mid;
	t_list	*head;

	head = lst;
	count = -1;
	while (++count >= 0 && lst != NULL)
		lst = lst->next;
	mid = count / 2;
	count = -1;
	lst = head;
	while (lst != NULL && ++count != mid)
		lst = lst->next;
	return (lst);
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
	{.content = 1, .next = &lst2[1]},
	{.content = 2, .next = &lst2[2]},
	{.content = 3, .next = &lst2[3]},
	{.content = 4, .next = NULL}
	};
	t_list	lst3[] = {
	{.content = 1, .next = NULL},
	};
	t_list	*result;

	result = ft_find_middle(lst1);
	printf("%d\n", result->content);
	result = ft_find_middle(lst2);
	printf("%d\n", result->content);
	result = ft_find_middle(lst3);
	printf("%d\n", result->content);
	return (0);
}
*/
