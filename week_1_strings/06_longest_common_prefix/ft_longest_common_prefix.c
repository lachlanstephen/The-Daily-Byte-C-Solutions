/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_common_prefix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:03:36 by lstephen          #+#    #+#             */
/*   Updated: 2024/02/25 15:44:17 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int	check_size(char *strs[])
{
	int		i;
	int		j;
	char	temp;

	i = -1;
	while (strs[0][++i] != 0)
	{
		temp = strs[0][i];
		j = 0;
		while (strs[++j][0] != '\0')
		{
			if (strs[j][i] != temp)
				return (i);
		}
	}
	return (i);
}

char	*ft_lcp(char *strs[])
{
	char	*result;
	int		len;
	int		i;

	i = -1;
	len = check_size(strs);
	if (len == -1)
		len++;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (++i < len)
		result[i] = strs[0][i];
	result[i] = '\0';
	return (result);
}

/*
int	main(void)
{
	char	*strs1[] = {"colorado", "color", "cold", "\0"};
	char	*strs2[] = {"a", "b", "c", "\0"};
	char	*strs3[] = {"spot", "spotty", "spotted", "\0"};

	printf("%s\n", ft_lcp(strs1));
	printf("%s\n", ft_lcp(strs2));
	printf("%s\n", ft_lcp(strs3));
	return (0);
}
*/
