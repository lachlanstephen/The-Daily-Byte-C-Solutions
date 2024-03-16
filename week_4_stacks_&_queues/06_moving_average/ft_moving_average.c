/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_average.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:37:19 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/16 01:50:47 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	g_nums[100];
int			g_cap;

void	pop_val(int	*count)
{
	int	i;

	i = -1;
	if (*count > 0)
	{
		while (++i < *count - 1)
			g_nums[i] = g_nums[i + 1];
		g_nums[i] = 0;
		(*count)--;
	}
}

int	moving_average(int num)
{
	int			i;
	static int	count;
	int			res;

	i = -1;
	res = 0;
	g_nums[count++] = num;
	while (count > g_cap)
		pop_val(&count);
	while (++i < count)
		res += g_nums[i];
	res /= count;
	return (res);
}

int	main(void)
{
	g_cap = 3;
	printf("%d\n", moving_average(3));
	printf("%d\n", moving_average(5));
	printf("%d\n", moving_average(7));
	printf("%d\n", moving_average(6));
	return (0);
}
