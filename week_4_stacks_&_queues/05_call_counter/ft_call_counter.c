/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:49:30 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/16 01:35:34 by darkwater        ###   ########.fr       */
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
static int	g_calls[100];

void	pop_val(void)
{
	int	i;

	i = -1;
	if (g_count > 0)
	{
		while (++i < g_count - 1)
			g_calls[i] = g_calls[i + 1];
		g_calls[i] = 0;
		g_count--;
	}
}

int	ping(int t)
{
	if (g_count >= 100)
		exit(1);
	g_calls[g_count++] = t;
	while (g_count > 0)
	{
		if (t - 3000 > g_calls[0])
			pop_val();
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
