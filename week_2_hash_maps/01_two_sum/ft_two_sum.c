/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_sum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:22:34 by darkwater         #+#    #+#             */
/*   Updated: 2024/02/26 23:17:15 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool	ft_two_sum(int *nums, int sum, int count)
{
	int	i;
	int	temp;
	int	map[1000];

	i = -1;
	while (++i < 1000)
		map[i] = 0;
	i = -1;
	while (++i < count)
	{
		temp = sum - nums[i];
		if (map[temp] == 1)
			return (true);
		map[nums[i]] = 1;
	}
	return (false);
}

/*
int	main(void)
{
	int	nums[][5] = {{1, 3, 8, 2},
			{3, 9, 13, 7},
			{4, 2, 6, 5, 2}};
	int sums[] = {10, 8, 4};
	int	count;

	for (int i = 0; i < 3; i++)
	{
		count = sizeof(nums[i]) / sizeof(nums[i][0]);
		printf("%s\n", ft_two_sum(nums[i], sums[i], count) ? "true" : "false");
	}
	return (0);
}
*/
