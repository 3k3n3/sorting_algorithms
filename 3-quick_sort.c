#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @x: Pointer to the first element
 * @y: Pointer to the second element
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Lomuto partition scheme for Quick sort
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The pivot index
 */
/* Function to partition the array using the last element as the pivot */
int partition(int *array, size_t size, int low, int high)
{
	/* Set the pivot as the last element of the partition */
	int *pivot, above, below;

	pivot = array + high;

	/* Iterate through the partitioned elements */
	for (above = below = low; below < high; below++)
	{
		/* If the current element is less than the pivot */
		if (array[below] < *pivot)
		{
			/* Move current element to section below pivot */
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++; /* Increment the above index */

		}
	}

	/* Move the pivot to its correct position */
	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	/* Return the index of the pivot */
	return (above);
}

/**
 * quicksort_recursive - Recursive helper function for Quick sort
 *
 * @size: The size of the array
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 */
void quicksort_recursive(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, size, low, high);

		quicksort_recursive(array, size, low, pivot_index - 1);
		quicksort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, size, 0, size - 1);
}
