#include "sort.h"

/**
 * selection_sort - function to sort array of ints ascending
 * @array: array given for sort
 * @size: size of given array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, temp, holder = 0;

	for (i = 0; i < size; i++)
	{
		temp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
			}
		}
		if (temp != i)
		{
			holder = array[i];
			array[i] = array[temp];
			array[temp] = holder;
			print_array(array, size);
		}
	}
}
