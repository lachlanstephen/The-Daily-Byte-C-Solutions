/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vacuum_cleaner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:49:54 by darkwater         #+#    #+#             */
/*   Updated: 2023/06/17 02:34:52 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

int	check_vertical(char *str, int i)
{
	if (str[i] == 'D')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}	

int	check_horizontal(char *str, int i)
{
	if (str[i] == 'L')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

bool	ft_original_pos(char *str)
{
	int	vert;
	int	hori;
	int	i;

	i = 0;
	vert = 0;
	hori = 0;
	while (str[i] != 0)
	{
		if (str[i] == 'L' || str[i] == 'R')
			hori += check_horizontal(str, i);
		else if (str[i] == 'U' || str[i] == 'D')
			vert += check_vertical(str, i);
		else
		{
			printf("Not a valid path");
			return (false);
		}
		i++;
	}
	if (vert == 0 && hori == 0)
		return (true);
	return (false);
}

/*
int	main(void)
{
	char	str1[] = "LR";
	char	str2[] = "URURD";
	char	str3[] = "RUULLDRD";
	char	str4[] = "";
	char	str5[] = "LRTESTFAIL";

	printf("%s\n", ft_original_pos(str1) ? "true" : "false");
	printf("%s\n", ft_original_pos(str2) ? "true" : "false");
	printf("%s\n", ft_original_pos(str3) ? "true" : "false");
	printf("%s\n", ft_original_pos(str4) ? "true" : "false");
	printf("%s\n", ft_original_pos(str5) ? "true" : "false");
	return (0);
}
*/	
