/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_nth_to_last_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:25:36 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/04 23:56:55 by lstephen         ###   ########.fr       */
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

void	list_reset(t_list *lst, t_list **arr)
{
	int	i;

	i = 0;
	while (arr[++i] != NULL)
	{
		lst->next = arr[i];
		lst = lst->next;
	}
}

t_list	*ft_del_nth_to_last(t_list *lst, int n)
{
	t_list	*head;
	int		count;

	head = lst;
	count = -1;
	while (++count >= 0 && lst != NULL)
		lst = lst->next;
	lst = head;
	count -= n;
	n = 0;
	while (lst != NULL)
	{
		if (count == 0)
		{
			head = lst->next;
			count--;
		}
		if ((count >= 0) && (n == count - 1))
			lst->next = lst->next->next;
		n++;
		lst = lst->next;
	}
	return (head);
}

/*
int	main(void)
{
	int		n;
	t_list	*result;
	t_list	lst[] = {
	{.content = 1, .next = &lst[1]},
	{.content = 2, .next = &lst[2]},
	{.content = 3, .next = NULL}
	};
	t_list	*backup[4] = {&lst[0], &lst[1], &lst[2], NULL};

	n = 1;
	result = ft_del_nth_to_last(lst, n);
	while (result->next != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("%d->NULL\n", result->content);
	list_reset(lst, backup);
	n = 2;
	result = ft_del_nth_to_last(lst, n);
	while (result->next != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("%d->NULL\n", result->content);
	list_reset(lst, backup);
	n = 3;
	result = ft_del_nth_to_last(lst, n);
	while (result->next != NULL)
	{
		printf("%d->", result->content);
		result = result->next;
	}
	printf("%d->NULL\n", result->content);
	return (0);
}
*/
