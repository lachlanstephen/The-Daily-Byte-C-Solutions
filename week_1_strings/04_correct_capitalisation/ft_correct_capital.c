/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_capital.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:21:38 by darkwater         #+#    #+#             */
/*   Updated: 2023/06/17 02:58:22 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool	check_capital(char *str, bool lowercase, bool uppercase)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] < 'a' || str[i] > 'z')
			&& (str[i] < 'A' || str[i] > 'Z'))
		{
			printf("Not a valid string!\n");
			return (false);
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (uppercase == true)
				return (false);
			else
				lowercase = true;
		}
		if (str[i] >= 'A' && str[i] <= 'Z' && lowercase == true)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_correct_capital(char *str)
{
	bool	uppercase;
	bool	lowercase;

	lowercase = false;
	uppercase = false;
	if (str[0] != 0 && str[1] != 0 && str[1] >= 'A' && str[1] <= 'Z')
		uppercase = true;
	if (check_capital(str, lowercase, uppercase) == false)
		return (false);
	else
		return (true);
}

/*
int	main(void)
{
	char	str1[] = "AUSTRALIA"; //True
	char	str2[] = "Calvin"; //True
	char	str3[] = "compUter"; //False
	char	str4[] = "coding"; //True
	char	str5[] = "TESTing"; //False
	char	str6[] = "This should fail"; //False

	printf("%s\n", ft_correct_capital(str1) ? "true" : "false");
	printf("%s\n", ft_correct_capital(str2) ? "true" : "false");
	printf("%s\n", ft_correct_capital(str3) ? "true" : "false");
	printf("%s\n", ft_correct_capital(str4) ? "true" : "false");
	printf("%s\n", ft_correct_capital(str5) ? "true" : "false");
	printf("%s\n", ft_correct_capital(str6) ? "true" : "false");
	return (0);
}
*/
