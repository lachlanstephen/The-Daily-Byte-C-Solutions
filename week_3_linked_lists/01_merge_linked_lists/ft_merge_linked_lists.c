/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_linked_lists.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:06:07 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/04 01:13:36 by darkwater        ###   ########.fr       */
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

void	free_list(t_list *lst)
{
	t_list	*temp;

	while (lst != NULL)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

int	ft_list_cmp(t_list *lst1, t_list *lst2, t_list *res)
{
	while (lst1 != NULL || lst2 != NULL)
	{
		if (lst2 == NULL || (lst1 != NULL && lst1->content <= lst2->content))
		{
			res->content = lst1->content;
			lst1 = lst1->next;
		}
		else
		{
			res->content = lst2->content;
			lst2 = lst2->next;
		}
		if (lst1 == NULL && lst2 == NULL)
			res->next = NULL;
		else
		{
			res->next = malloc(sizeof(t_list));
			if (res->next == NULL)
				return (1);
		}
		res = res->next;
	}
	return (0);
}

t_list	*ft_merge_lists(t_list *lst1, t_list *lst2)
{
	t_list	*res;
	t_list	*head;

	res = malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	head = res;
	if (ft_list_cmp(lst1, lst2, res) == 1)
	{
		free_list(head);
		return (NULL);
	}
	return (head);
}

/*
int	main(void)
{
	t_list	list1[] = {
		{ .content = 1, .next = &list1[1] },
		{ .content = 2, .next = &list1[2] },
		{ .content = 3, .next = NULL }
	};

	t_list	list2[] = {
		{ .content = 4, .next = &list2[1] },
		{ .content = 5, .next = &list2[2] },
		{ .content = 6, .next = NULL },
	};

	t_list	list3[] = {
		{ .content = 1, .next = &list3[1] },
		{ .content = 3, .next = &list3[2] },
		{ .content = 5, .next = NULL }
	};

	t_list	list4[] = {
		{ .content = 2, .next = &list4[1] },
		{ .content = 4, .next = &list4[2] },
		{ .content = 6, .next = NULL }
	};

	t_list	list5[] = {
		{ .content = 4, .next = &list5[1] },
		{ .content = 4, .next = &list5[2] },
		{ .content = 7, .next = NULL }
	};

	t_list	list6[] = {
		{ .content = 1, .next = &list6[1] },
		{ .content = 5, .next = &list6[2] },
		{ .content = 6, .next = NULL }
	};

	t_list	*result;
	t_list	*head;

	result = ft_merge_lists(list1, list2);
	head = result;
	while (result != NULL)
	{
		printf("%d\n", result->content);
		result = result->next;
	}
	free_list(head);
	result = ft_merge_lists(list3, list4);
	head = result;
	while (result != NULL)
	{
		printf("%d\n", result->content);
		result = result->next;
	}
	free_list(head);
	result = ft_merge_lists(list5, list6);
	head = result;
	while (result != NULL)
	{
		printf("%d\n", result->content);
		result = result->next;
	}
	free_list(head);
	return (0);
}
*/
