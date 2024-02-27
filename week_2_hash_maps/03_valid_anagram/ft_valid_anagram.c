/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_anagram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:44:00 by lstephen          #+#    #+#             */
/*   Updated: 2024/02/27 20:51:48 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char	*ft_to_lower(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != 0)
		i++;
	res = malloc(sizeof(char) * i);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != 0)
	{
		res[i] = str[i];
		if (res[i] >= 'A' && res[i] <= 'Z')
			res[i] += ' ';
	}
	res[i] = '\0';
	return (res);
}

bool	ft_valid_anagram(char *str1, char *str2)
{
	int		letters[26];
	int		i;
	char	*temp1;
	char	*temp2;

	i = -1;
	temp1 = ft_to_lower(str1);
	temp2 = ft_to_lower(str2);
	while (++i < 26)
		letters[i] = 0;
	i = -1;
	while (temp1[++i] != 0)
		letters[(temp1[i]) - 'a']++;
	i = -1;
	while (temp2[++i] != 0)
		letters[(temp2[i]) - 'a']--;
	i = -1;
	while (++i < 26)
	{
		if (letters[i] != 0)
			return (false);
	}
	return (true);
}

/*
int	main(void)
{
	char	*str1[] = {"cat", "tac"};
	char	*str2[] = {"listen", "silent"};
	char	*str3[] = {"program", "function"};

	printf("%s\n", ft_valid_anagram(str1[0], str1[1]) ? "true" : "false");
	printf("%s\n", ft_valid_anagram(str2[0], str2[1]) ? "true" : "false");
	printf("%s\n", ft_valid_anagram(str3[0], str3[1]) ? "true" : "false");
	return (0);
}
*/
