/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_unique_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:30:01 by lstephen          #+#    #+#             */
/*   Updated: 2024/02/28 16:40:26 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_first_unique_char(char *str)
{
	int	i;
	int	characters[95];

	i = -1;
	while (++i < 95)
		characters[i] = 0;
	i = -1;
	while (str[++i] != 0)
		characters[(str[i] - ' ')]++;
	i = -1;
	while (str[++i] != 0)
	{
		if (characters[(str[i] - ' ')] == 1)
			return (i);
	}
	return (-1);
}

/*
int	main(void)
{
	char	*strs[] = {"abcabd", "thedailybyte", "developer"};

	for (int i = 0; i < 3; i++)
		printf("%d\n", ft_first_unique_char(strs[i]));
	return (0);
}
*/
