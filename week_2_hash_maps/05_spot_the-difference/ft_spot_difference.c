/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spot_difference.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:38:52 by lstephen          #+#    #+#             */
/*   Updated: 2024/02/29 15:48:11 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	ft_spot_diff(char *str1, char *str2)
{
	int		i;
	int		letters[26];

	i = -1;
	while (++i < 26)
		letters[i] = 0;
	i = -1;
	while (str1[++i] != 0)
		letters[(str1[i]) - 'a'] = 1;
	i = -1;
	while (str2[++i] != 0)
	{
		if (letters[(str2[i]) - 'a'] != 1)
			return (str2[i]);
	}
	return (0);
}

/*
int	main(void)
{
	char	*strs1[] = {"foobar", "barfoot"};
	char	*strs2[] = {"ide", "idea"};
	char	*strs3[] = {"coding", "ingcod"};

	printf("%c\n", ft_spot_diff(strs1[0], strs1[1]));
	printf("%c\n", ft_spot_diff(strs2[0], strs2[1]));
	printf("%c\n", ft_spot_diff(strs3[0], strs3[1]));
	return (0);
}
*/
