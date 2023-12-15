#include "sort.h"
/**
 * swap - function
 * @array : unsorted array
 * @size : size of array
 * @nb1 : number 1
 * @nb2 : number 2
 */
void swap(int *array, int *nb1, int *nb2, size_t size)
{
	int temp;

	temp = array[nb1];
	array[nb1] = array[nb2];
	array[nb2] = temp;
	print_array(array, size);
}

/**
 * lomuto_par - function
 * @array : array to partitioned
 * @small : small index
 * @size : size of array
 * @high : high index
 * Return: size_ti
 */
size_t lomuto_par(int *array, size_t size, int small, int high)
{
	int i, j, pivot;

	pivot = array[high];
	i = small;
	for (j = small; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			if (j > i)
				swap(array, i, j, size);
			i++;
		}
	}
	if (array[i] > pivot)
		swap(array, i, high, size);
	return (i);
}
/**
 * qs - function
 * @array: unsorted array
 * @size:  size of the array
 * @small: small index
 * @high: high index
 */
void qs(int *array, size_t size, int small, int high)
{
	int par;

	if (small < high)
	{
		par = lomuto_par(array, small, high, size);
		qs(array, size, small, par - 1);
		qs(array, size, par + 1, high);
	}
}

/**
 * quick_sort - function
 * @array : unsorted array
 * @size : size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	high = size - 1;
	qs(array, size, 0, high);
}
