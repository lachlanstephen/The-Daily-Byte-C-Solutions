/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_characters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:50:16 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/10 05:15:53 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool	ft_balanced_brackets(char *str)
{
	int	letters[100];
	int	count;
	int	i;

	count = 0;
	i = -1;
	letters[0] = 0;
	while (str[++i] != 0)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			letters[count++] = str[i];
		else
		{
			if (letters[count - 1] == str[i] - 1
				|| letters[count - 1] == str[i] - 2)
			{
				letters[count-- - 1] = 0;
				continue ;
			}
			break ;
		}
	}
	if (letters[0] == 0)
		return (true);
	return (false);
}

/*
int	main(void)
{
	char	*strs[] = {"(){}[]", "(({[]}))", "{(})", ""};

	for (int i = 0; i < 4; i++)
		printf("%s\n", ft_balanced_brackets(strs[i]) ? "true" : "false");
	return (0);
}
*/
