/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:10 by darkwater         #+#    #+#             */
/*   Updated: 2024/02/23 22:55:37 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdbool.h"
#include "unistd.h"
#include "stdlib.h"

int	ft_atoi_binary(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != 0)
	{
		res *= 2;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

char	*ft_itoa_binary(char *res, int len, int num)
{
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	else
	{
		while (--len >= 0)
		{
			res[len] = num % 2 + '0';
			num /= 2;
		}
	}
	return (res);
}

char	*arg_parsing(char *strs[])
{
	int		nums[2];
	int		i;
	char	*res;

	nums[0] = ft_atoi_binary(strs[0]);
	nums[1] = ft_atoi_binary(strs[1]);
	nums[0] += nums[1];
	nums[1] = nums[0];
	i = 0;
	while (nums[1] != 0)
	{
		i++;
		nums[1] /= 2;
	}
	res = malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	ft_itoa_binary(res, i, nums[0]);
	printf("%s\n", res);
	return (res);
}

/*
int	main(void)
{
	char	*a[] = {"100", "1"};
	char	*b[] = {"11", "1"};
	char	*c[] = {"1", "0"};
	char	*d[] = {"0", "0"};

	(void)arg_parsing(a);
	(void)arg_parsing(b);
	(void)arg_parsing(c);
	(void)arg_parsing(d);
	return (0);
}
*/
