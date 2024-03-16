/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:49:30 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/17 02:28:43 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
typedef struct
{
	int	(*ping)(int t);
}		CallCounter;
*/

static int	g_count;

void	pop_val(int *calls)
{
	int	i;

	i = -1;
	if (g_count > 0)
	{
		while (++i < g_count - 1)
			calls[i] = calls[i + 1];
		calls[i] = 0;
		g_count--;
	}
}

int	ping(int t)
{
	static int	calls[100];

	if (g_count >= 100)
		exit(1);
	calls[g_count++] = t;
	while (g_count > 0)
	{
		if (t - 3000 > calls[0])
			pop_val(calls);
		else
			break ;
	}
	return (g_count);
}

/*
int	main(void)
{
	ping(1);
	printf("%d (%d call within the last 3 seconds)\n", g_count, g_count);
	ping(300);
	printf("%d (%d call within the last 3 seconds)\n", g_count, g_count);
	ping(3000);
	printf("%d (%d call within the last 3 seconds)\n", g_count, g_count);
	ping(3002);
	printf("%d (%d call within the last 3 seconds)\n", g_count, g_count);
	ping(7000);
	printf("%d (%d call within the last 3 seconds)\n", g_count, g_count);
	return (0);
}
*/
