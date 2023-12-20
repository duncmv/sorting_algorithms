#include <stdio.h>
#include "sort.h"

/**
 * switx - function
 * @nb1: first integer
 * @nb2: second integer
 */

void switx(int *nb1, int *nb2)
{
	int tmp = *nb1;
	*nb1 = *nb2;
	*nb2 = tmp;
}

/**
 * shell_sort - function
 * @array: array of integers
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (!array || size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i; j < size - gap; j += gap)
			{
				while (array[j] > array[j + gap])
				{
					switx(&array[j], &array[j + gap]);
					if (j >= gap)
						j -= gap;
					else
						break;
				}
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
