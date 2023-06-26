#include "sort.h"

/**
 * swap - swaps integers x and y in order
 *
 * @x: first integer
 * @y: second integer
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}


/**
 * bubble_sort - Sorts integers in ascending order
 *
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
		/*Last i elements are already in place*/
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
}
