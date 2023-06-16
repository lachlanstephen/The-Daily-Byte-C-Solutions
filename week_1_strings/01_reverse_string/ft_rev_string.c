/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:28:56 by darkwater         #+#    #+#             */
/*   Updated: 2023/06/14 03:32:44 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_rev_string(char *str)
{
	char	temp;
	int		i;
	int		count;

	i = 0;
	count = count_length(str) - 1;
	while (i < count)
	{
		temp = str[i];
		str[i] = str[count];
		str[count] = temp;
		i++;
		count--;
	}
	return (str);
}

/*
int	main(void)
{
	char	str1[] = "Cat";
	char	str2[] = "The Daily Byte";
	char	str3[] = "civic";
	char	str4[] = "";

	printf("%s\n", ft_rev_string(str1));
	printf("%s\n", ft_rev_string(str2));
	printf("%s\n", ft_rev_string(str3));
	printf("%s\n", ft_rev_string(str4));
	return (0);
}
*/
