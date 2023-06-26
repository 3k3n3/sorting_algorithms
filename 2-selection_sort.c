#include "sort.h"

/**
 * swap - swaps integers x and y in order
 *
 * @x: current integer
 * @y: lowest integer
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sorts integers in ascending order
 *
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/*Find smallest integer in array*/
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
