
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

int* ft_greater_elements(int* nums1, int nums1Len, int* nums2, int nums2Len) {
    int map[4];
  int *res = (int*)malloc(sizeof(int) * nums1Len);
  if (res == NULL)
    return NULL;
  for (int i = 0; i < nums1Len; i++)
      res[i] = -1;

  int stack[MAX_SIZE];
  int top = -1;

  for (int i = 0; i < nums2Len; i++) {
    map[i] = -1;
  }
  for (int i = 0; i < nums1Len; i++) {
    for (int j = 0; j < nums2Len; j++) {
      if (nums1[i] == nums2[j]) {
        map[j] = i;
        break;
      }
    }
  }
  int count = 0;
  for (int i = 0; i < nums2Len; i++) {
    if (top != -1 && nums2[i] > stack[top]) {
      if (i > 0 && map[i - count] != -1) {
        res[map[i - count]] = nums2[i];
        count = 0;
        top--;
		i--;
      }
    }
    else{
      count++;
      stack[++top] = nums2[i];
  }
  }
  return res;
}

int     main(void)
{
        int     nums1[] = {4, 1, 2};
        int     nums2[] = {1, 3, 4, 2};
        int     nums3[] = {2, 4};
        int     nums4[] = {1, 2, 3, 4};
        int     *res;
        int     len;
        int     i;

        i = -1;
        len = sizeof(nums1) / sizeof(int);
        res = ft_greater_elements(nums1, len, nums2, 4);
        while (++i < len - 1)
                printf("%d, ", res[i]);
        printf("%d\n", res[i]);
        free(res);
        i = -1;
        len = sizeof(nums3) / sizeof(int);
        res = ft_greater_elements(nums3, len, nums4, 4);
        while (++i < len - 1)
                printf("%d, ", res[i]);
        printf("%d\n", res[i]);
        free(res);
        return (0);
}

