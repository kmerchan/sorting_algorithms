#include "sort.h"

/**
 * quick_sort - sorts an array of integers using quick sort
 * array is sorted in ascending order
 * Lomuto partition scheme is used
 * @array: given array to sort
 * @size: size of array to sort
 *
 */

void quick_sort(int *array, size_t size)
{
/* quick sort: */
/* sorts smaller and smaller pieces into lower on left, higher on right */

	quick_sort_recursion(array, size, 0, size - 1);
}

/**
 * quick_sort_recursion - recursively sorts using quick sort
 * @array: array to sort
 * @size: size of array
 * @start: start of partition to sort
 * @end: end of partition to sort
 *
 */

void quick_sort_recursion(int *array, size_t size, size_t start, size_t end)
{
	unsigned int i = 0, pivot_index = 0, placement = 0;
	int holder;

	pivot_index = end;
	placement = start;
	for (i = start; i < pivot_index; i++)
	{
		if (array[i] < array[pivot_index] && i != placement)
		{
			holder = array[i];
			array[i] = array[placement];
			array[placement] = holder;
			placement++;
			print_array(array, size);
		}
		else if (array[i] < array[pivot_index])
			placement++;
	}
	if (placement != pivot_index)
	{
		holder = array[placement];
		array[placement] = array[pivot_index];
		array[pivot_index] = holder;
		print_array(array, size);
	}
	if (placement != start)
		quick_sort_recursion(array, size, 0, placement - 1);
	if (placement != end)
		quick_sort_recursion(array, size, placement + 1, size - 1);
}
