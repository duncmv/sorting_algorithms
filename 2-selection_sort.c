#include "sort.h"

/**
 * selection_sort - sorts through an array using selection sort algo
 * @array: pointer to an array
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t j_min = 0, j, i, check;
	int temp;

	if (size < 2)
		return;

	while (j_min < size)
	{
		check = 0;
		temp = array[j_min];
		for (j = j_min + 1; j < size; j++)
		{
			if (array[j] < temp)
			{
				temp = array[j];
				i = j;
				check = 1;
			}
		}
		if (check == 1)
		{
			array[i] = array[j_min];
			array[j_min] = temp;
			print_array(array, size);
		}
		++j_min;
	}
}
