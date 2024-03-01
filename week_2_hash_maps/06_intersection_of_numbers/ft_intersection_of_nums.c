/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_of_nums.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:51 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/01 16:57:55 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	num_count(int *arr, int *nums, int arr_size)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < arr_size)
	{
		if (nums[(arr[i])] == 1)
		{
			count++;
			nums[(arr[i])]++;
		}
	}
	return (count);
}

int	*ft_num_intersection(int *arr1, int *arr2, int arr1_size, int arr2_size)
{
	int	i;
	int	numbers[100];
	int	*res;
	int	count;
	int	step;

	i = -1;
	step = -1;
	while (++i < 100)
		numbers[i] = 0;
	i = -1;
	while (++i < arr1_size)
		numbers[(arr1[i])] = 1;
	i = -1;
	count = num_count(arr2, numbers, arr2_size);
	res = malloc(sizeof(int) * count);
	if (res == NULL || count == 0)
		return (NULL);
	while (++i < arr2_size)
	{
		if (numbers[(arr2[i])] == 2)
			res[++step] = arr2[i];
		numbers[(arr2[i])]--;
	}
	return (res);
}

/*
int	main(void)
{
	int		nums1[] = {2, 4, 4, 2};
	int		nums2[] = {2, 4};
	int		nums3[] = {1, 2, 3, 3};
	int		nums4[] = {3, 3};
	int		nums5[] = {2, 4, 6, 8};
	int		nums6[] = {1, 3, 5, 7};
	int		*res;
	size_t	arr1_size;
	size_t	arr2_size;
	int		i;

	i = -1;
	arr1_size = sizeof(nums1) / sizeof(nums1[0]);
	arr2_size = sizeof(nums2) / sizeof(nums2[0]);
	res = ft_num_intersection(nums1, nums2, arr1_size, arr2_size);
	printf("[");
	while (++i < 1)
		printf("%d, ", res[i]);
	printf("%d]\n", res[i]);
	free(res);
	arr1_size = sizeof(nums3) / sizeof(nums3[0]);
	arr2_size = sizeof(nums4) / sizeof(nums4[0]);
	res = ft_num_intersection(nums3, nums4, arr1_size, arr2_size);
	printf("[%d]\n", res[1]);
	free(res);
	arr1_size = sizeof(nums5) / sizeof(nums5[0]);
	arr2_size = sizeof(nums6) / sizeof(nums6[0]);
	res = ft_num_intersection(nums5, nums6, arr1_size, arr2_size);
	printf("NULL\n");
	free(res);
	return (0);
}
*/
