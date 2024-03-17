/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_keystrokes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:58:44 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/10 23:26:39 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void	create_stack(char *str, int *count, int *stack)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		if (str[i] == '#' && *count > 0)
			stack[(*count)-- - 1] = 0;
		else
			stack[(*count)++] = str[i];
	}
}

bool	ft_compare_keystrokes(char *str1, char *str2)
{
	int	counts[2];
	int	keys1[100];
	int	keys2[100];

	counts[0] = 0;
	counts[1] = 0;
	create_stack(str1, &(counts[0]), keys1);
	create_stack(str2, &(counts[1]), keys2);
	while (--counts[0] >= 0)
	{
		if (keys1[(counts[0])] != keys2[(counts[0])])
			return (false);
	}
	return (true);
}

/*
int	main(void)
{
	char	*strs1[] = {"ABC#", "CD##AB"}; //return true
	char	*strs2[] = {"como#pur#ter", "computer"}; //return true
	char	*strs3[] = {"cof#dim#ng", "code"}; //return false

	printf("%s\n", ft_compare_keystrokes(strs1[0], strs1[1]) ? "true" : "false");
	printf("%s\n", ft_compare_keystrokes(strs2[0], strs2[1]) ? "true" : "false");
	printf("%s\n", ft_compare_keystrokes(strs3[0], strs3[1]) ? "true" : "false");
	return (0);
}
*/
