/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_average.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:37:19 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/17 02:21:56 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	g_cap;

void	pop_val(int	*count, int *nums_q)
{
	int	i;

	i = -1;
	if (*count > 0)
	{
		while (++i < *count - 1)
			nums_q[i] = nums_q[i + 1];
		nums_q[i] = 0;
		(*count)--;
	}
}

int	moving_average(int num)
{
	int			i;
	static int	count;
	static int	nums_q[100];
	int			res;

	i = -1;
	res = 0;
	nums_q[count++] = num;
	while (count > g_cap)
		pop_val(&count, nums_q);
	while (++i < count)
		res += nums_q[i];
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
