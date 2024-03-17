/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_adjacent_dups.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:20:31 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/13 03:41:49 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_rem_duplicates(char *str)
{
	int		count;
	int		i;
	char	*res;
	int		store[100];

	i = -1;
	count = 0;
	store[0] = 0;
	while (str[++i] != 0)
	{
		if (count > 0 && str[i] == store[count - 1])
			store[--count] = 0;
		else
			store[count++] = str[i];
	}
	res = malloc(sizeof(char) * count + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
		res[i] = store[i];
	res[i] = '\0';
	return (res);
}

/*
int	main(void)
{
	char	*strs[] = {"abccba", "foobar", "abccbefggfe"};

	for (int i = 0; i < 3; i++)
		printf("%s\n", ft_rem_duplicates(strs[i]));
	return (0);
}
*/
