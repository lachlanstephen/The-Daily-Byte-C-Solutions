/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greater_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:24:27 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/13 23:08:34 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	*ft_greater_elements(int *nums1, int *nums2, int len)
{
	int	*res;
	int	count[3];

	count[0] = -1;
	res = malloc(sizeof(int) * len);
	if (res == NULL)
		return (NULL);
	while (++count[0] < len)
	{
		count[1] = -1;
		while (nums2[++(count[1])] != 0)
		{
			if (nums2[(count[1])] == nums1[(count[0])])
			{
				count[2] = count[1];
				while (nums2[++(count[2])] != 0)
				{
					if (nums2[(count[2])] > nums1[(count[0])])
					{
						res[(count[0])] = nums2[(count[2])];
						break ;
					}
				}
				if (nums2[(count[2])] == 0)
					res[(count[0])] = -1;
				break ;
			}
		}
	}
	return (res);
}

int	main(void)
{
	int	nums1[] = {4, 1, 2};
	int	nums2[] = {1, 3, 4, 2, 0};
	int	nums3[] = {2, 4};
	int	nums4[] = {1, 2, 3, 4, 0};
	int	*res;
	int	len;
	int	i;

	i = -1;
	len = sizeof(nums1) / sizeof(int);
	res = ft_greater_elements(nums1, nums2, len);
	while (++i < len - 1)
		printf("%d, ", res[i]);
	printf("%d\n", res[i]);
	free(res);
	i = -1;
	len = sizeof(nums3) / sizeof(int);
	res = ft_greater_elements(nums3, nums4, len);
	while (++i < len - 1)
		printf("%d, ", res[i]);
	printf("%d\n", res[i]);
	free(res);
	return (0);
}
