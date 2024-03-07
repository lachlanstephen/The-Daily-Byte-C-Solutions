/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_of_cycle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:37:59 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/08 01:12:23 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

t_list	*ft_cycle_start(t_list	*lst)
{
	int	values[10000];
	int	i;

	i = -1;
	while (++i < 10000)
		values[i] = 0;
	while (lst != NULL)
	{
		if (values[(lst->content)] == 1)
			return (lst);
		values[(lst->content)] = 1;
		lst = lst->next;
	}
	return (NULL);
}

/*
int	main(void)
{
	int		i;
	t_list	lst1[] = {
	{.content = 1, .next = &lst1[1]},
	{.content = 2, .next = &lst1[2]},
	{.content = 3, .next = NULL}
	};
	t_list	lst2[] = {
	{.content = 1, .next = &lst2[1]},
	{.content = 2, .next = &lst2[2]},
	{.content = 3, .next = &lst2[3]},
	{.content = 4, .next = &lst2[4]},
	{.content = 5, .next = &lst2[2]}
	};
	t_list	lst3[] = {
	{.content = 1, .next = &lst3[1]},
	{.content = 9, .next = &lst3[2]},
	{.content = 3, .next = &lst3[3]},
	{.content = 7, .next = &lst3[3]}
	};
	t_list	*result;
	t_list	*backup;

	i = -1;
	backup = lst1;
	result = ft_cycle_start(lst1);
	while (++i < 3)
	{
		printf("Address: %p, Content: %d, Next: %p\n",
			(void *)backup, backup->content, (void *)backup->next);
		backup = backup->next;
	}
	if (result == NULL)
		printf("NULL\n\n");
	else
		printf("Start of Cycle: Address: %p, Content: %d\n\n",
			(void *)result, result->content);
	i = -1;
	backup = lst2;
	result = ft_cycle_start(lst2);
	while (++i < 5)
	{
		printf("Address: %p, Content: %d, Next: %p\n",
			(void *)backup, backup->content, (void *)backup->next);
		backup = backup->next;
	}
	if (result == NULL)
		printf("NULL\n");
	else
		printf("Start of Cycle: Address: %p, Content: %d\n\n",
			(void *)result, result->content);
	i = -1;
	backup = lst3;
	result = ft_cycle_start(lst3);
	while (++i < 4)
	{
		printf("Address: %p, Content: %d, Next: %p\n",
			(void *)backup, backup->content, (void *)backup->next);
		backup = backup->next;
	}
	if (result == NULL)
		printf("NULL\n");
	else
		printf("Start of Cycle: Address: %p, Content: %d\n",
			(void *)result, result->content);
	return (0);
}
*/
