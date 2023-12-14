#include "sort.h"

/**
 * shell_sort - shell sort func
 * @array: unsorted array
 * @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	size_t knuth[100];
	size_t h = 1;
	size_t i = 0, j, x, check1 = 0, check2 = 0, temp;

	if (size < 2)
		return;

	while (h < size)
	{
		knuth[i++] = h;
		h = h * 3 + 1;
	}
	i--;

	while (1)
	{
		check1 = 0;
		check2 = 0;
		for (j = 0; j < size; j++)
		{
			x = j + knuth[i];
			if (x < size && (array[j] > array[x]))
			{
				temp = array[x];
				array[x] = array[j];
				array[j] = temp;
				check1 = 1;
			}
		}
		if (check1 == 0)
			continue;
		for (j = 0; j < size - 2; j++)
		{
			if (array[j] > array[j + 1])
			{
				print_array(array, size);
				if (i != 0)
					i--;
				check2 = 1;
				break;
			}
		}
		if (check2 == 0)
			break;
	}
}