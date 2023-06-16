/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_palindrome.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:16:24 by darkwater         #+#    #+#             */
/*   Updated: 2023/06/15 19:40:07 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	i--;
	return (i);
}

bool	ft_val_palindrome(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = str_len(str);
	while (str[i] != 0 && i < count)
	{
		while ((str[i] < 'a' || str[i] > 'z')
			&& (str[i] < 'A' || str[i] > 'Z'))
			i++;
		while ((str[count] < 'a' || str[count] > 'z')
			&& (str[count] < 'A' || str[count] > 'Z'))
			count--;
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ' ';
		if (str[count] >= 'A' && str[count] <= 'Z')
			str[count] += ' ';
		if (str[i] != str[count])
			return (false);
		i++;
		count--;
	}
	return (true);
}

/*
int	main(void)
{
	char	str1[] = "level";
	char	str2[] = "algorithm";
	char	str3[] = "A man, a plan, a canal: Panama.";
	char	str4[] = "";

	printf("%s\n", ft_val_palindrome(str1) ? "true" : "false");
	printf("%s\n", ft_val_palindrome(str2) ? "true" : "false");
	printf("%s\n", ft_val_palindrome(str3) ? "true" : "false");
	printf("%s\n", ft_val_palindrome(str4) ? "true" : "false");
	return (0);
}
*/
