/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jewels_and_stones.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:02:42 by lstephen          #+#    #+#             */
/*   Updated: 2024/02/27 12:16:05 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_jewels_stones(char *jewels, char *stones)
{
	int	i;
	int	store[95];
	int	count;

	i = -1;
	count = 0;
	while (++i < 95)
		store[i] = 0;
	i = -1;
	while (jewels[++i] != '\0')
		store[(jewels[i] - ' ')] = 1;
	i = -1;
	while (stones[++i] != '\0')
	{
		if (store[(stones[i] - ' ')] == 1)
			count++;
	}
	return (count);
}

/*
int	main(void)
{
	char	*invent1[] = {"abc", "ac"};
	char	*invent2[] = {"Af", "AaaddfFf"};
	char	*invent3[] = {"AYOPD", "ayopd"};

	printf("%d\n", ft_jewels_stones(invent1[0], invent1[1]));
	printf("%d\n", ft_jewels_stones(invent2[0], invent2[1]));
	printf("%d\n", ft_jewels_stones(invent3[0], invent3[1]));
	return (0);
}
*/
