/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_pal_w_removal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:57:36 by lstephen          #+#    #+#             */
/*   Updated: 2024/02/25 16:28:01 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	return (i);
}

bool	ft_is_valid(char *str)
{
	int		i;
	int		j;
	bool	removed;

	i = -1;
	j = ft_strlen(str);
	removed = false;
	while (true)
	{
		while (++i < j && str[i] == str[j])
			j--;
		if (str[i] != str[j] && i < j)
		{
			if (removed == true)
				break ;
			i++;
			removed = true;
			continue ;
		}
		return (true);
	}
	return (false);
}

/*
int	main(void)
{
	char	str1[] = "abcba";
	char	str2[] = "foobof";
	char	str3[] = "abccab";

	printf("%s\n", ft_is_valid(str1) ? "true" : "false");
	printf("%s\n", ft_is_valid(str2) ? "true" : "false");
	printf("%s\n", ft_is_valid(str3) ? "true" : "false");
	return (0);
}
*/
