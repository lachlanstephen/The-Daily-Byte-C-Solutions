/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_cycle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:26:26 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/07 01:44:43 by darkwater        ###   ########.fr       */
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

bool	ft_contains_cycle(t_list *lst)
{
	int				nums[10000];
	long unsigned	i;

	i = 0;
	while (i < (sizeof(nums) / sizeof(int)))
		nums[i++] = 0;
	while (lst != NULL)
	{
		if (nums[(lst->content)] == 1)
			return (true);
		nums[(lst->content)] = 1;
		lst = lst->next;
	}
	return (false);
}

/*
int	main(void)
{
	t_list	lst1[] = {
	{.content = 1, .next = &lst1[1]},
	{.content = 2, .next = &lst1[2]},
	{.content = 3, .next = &lst1[0]}
	};
	t_list	lst2[] = {
	{.content = 1, .next = &lst2[1]},
	{.content = 2, .next = &lst2[2]},
	{.content = 3, .next = NULL}
	};
	t_list	lst3[] = {
	{.content = 1, .next = &lst3[0]}
	};

	printf("%s\n", ft_contains_cycle(lst1) ? "true" : "false");
	printf("%s\n", ft_contains_cycle(lst2) ? "true" : "false");
	printf("%s\n", ft_contains_cycle(lst3) ? "true" : "false");
	return (0);
}
*/
