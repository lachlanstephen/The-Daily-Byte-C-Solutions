/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uncommon_words.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:45:26 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/03 03:37:56 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	total_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
}

void	arr_reset(int *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		arr[i] = 0;
}

void	data_erase(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		str[i] = '.';
}

int	word_len(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		if (str[i] == ' ')
			break ;
	}
	return (i);
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (str[++i] != 0)
	{
		if (str[i] == ' ')
			count++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		i;
	int		count;
	char	**res;
	int		len;
	int		step;

	i = -1;
	if (str[0] == 0)
		return (NULL);
	len = 0;
	step = -1;
	count = count_words(str);
	res = malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	res[count] = NULL;
	count = -1;
	len = word_len(&str[0]);
	res[++step] = malloc(sizeof(char) * len + 1);
	if (res[step] == NULL)
	{
		total_free(res);
		return (NULL);
	}
	while (str[++i] != 0)
	{
		if (str[i] == ' ')
		{
			res[step][++count] = '\0';
			len = word_len(&str[i + 1]);
			res[++step] = malloc(sizeof(char) * len + 1);
			if (res[step] == NULL)
			{
				total_free(res);
				return (NULL);
			}
			count = -1;
			continue ;
		}
		res[step][++count] = str[i];
	}
	res[step][++count] = '\0';
	return (res);
}

int	unique_word_count(char **arr)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (arr[++i] != NULL)
	{
		if (arr[i][0] == '.')
			continue ;
		count++;
	}
	return (count);
}

char	**join_arrays(char **arr1, char **arr2)
{
	int		i;
	int		count;
	int		step;
	char	**res;

	i = -1;
	step = -1;
	count = unique_word_count(arr1);
	count += unique_word_count(arr2);
	res = malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	while (arr1[++i] != NULL)
	{
		if (arr1[i][0] != '.')
			res[++step] = arr1[i];
		else
			free(arr1[i]);
	}
	i = -1;
	while (arr2[++i] != NULL)
	{
		if (arr2[i][0] != '.')
			res[++step] = arr2[i];
		else
			free(arr2[i]);
	}
	res[++step] = NULL;
	return (res);
}

char	**ft_uncommon_words(char *str1, char *str2)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		letters[25];
	char	**first_split;
	char	**second_split;
	char	**res;

	i = -1;
	first_split = ft_split(str1);
	second_split = ft_split(str2);
	arr_reset(letters, 25);
	while (first_split[++i] != NULL)
	{
		j = -1;
		while (first_split[i][++j] != 0)
			letters[j] = first_split[i][j] - 'a';
		k = -1;
		while (second_split[++k] != NULL)
		{
			j = -1;
			while (second_split[k][++j] != 0)
			{
				if (letters[j] != (second_split[k][j] - 'a'))
					break ;
			}
			if (second_split[k][j] == 0 && letters[j] == 0)
			{
				data_erase(second_split[k]);
				j = i - 1;
				while (first_split[++j] != NULL)
				{
					l = -1;
					while (first_split[j][++l] != 0)
					{
						if (letters[l] != (first_split[j][l] - 'a'))
							break ;
					}
					if (first_split[j][l] == 0 && letters[l] == 0)
						data_erase(first_split[j]);
				}
			}
		}
		arr_reset(letters, 25);
	}
	res = join_arrays(first_split, second_split);
	free(first_split);
	free(second_split);
	return (res);
}

/*
int	main(void)
{
	char	*sentences1[] = {"the quick", "brown fox"};
	char	*sentences2[] = {"the tortoise beat the haire",
			"the tortoise lost to the haire"};
	char	*sentences3[] = {"copper coffee pot", "hot coffee pot"};
	char	**result;
	int		i;

	i = -1;
	result = ft_uncommon_words(sentences1[0], sentences1[1]);
	printf("[");
	while (result[++i + 1] != NULL)
		printf("%s, ", result[i]);
	printf("%s]\n[", result[i]);
	total_free(result);
	i = -1;
	result = ft_uncommon_words(sentences2[0], sentences2[1]);
	while (result[++i + 1] != NULL)
		printf("%s, ", result[i]);
	printf("%s]\n[", result[i]);
	total_free(result);
	i = -1;
	result = ft_uncommon_words(sentences3[0], sentences3[1]);
	while (result[++i + 1] != NULL)
		printf("%s, ", result[i]);
	printf("%s]\n", result[i]);
	total_free(result);
	return (0);
}
*/
