#include "sort.h"

/**
 * counting_sort - sorts an array of ints ascending
 * @array: array given to be sorted
 * @size: size of given array
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{	size_t i = 0, temp = 0, count = 0;
	int *cnt_arr = NULL, *output = NULL, max = 0, j = 0;

	output = malloc(sizeof(int) * size);
	if (array == NULL || output == NULL)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	cnt_arr = malloc(sizeof(int) * (max + 1));
	if (cnt_arr == NULL)
	{
		free(output);
		return;
	}
	for (j = 0; j <= max; j++)
/* all zeroes set in array */
		cnt_arr[j] = 0;
	for (i = 0; i < size; i++)
/* store count each element in index */
		cnt_arr[array[i]]++;
	for (j = 0; j < max + 1; j++)
/* storing count */
	{
		temp = cnt_arr[j];
		cnt_arr[j] += count;
		count += temp;
	}
	print_array(cnt_arr, max + 1);
	for (i = size - 1; i < size; i--)
/* find indexes in count_arr, set in output array */
	{
		output[cnt_arr[array[i]] - 1] = array[i];
		cnt_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
/* copy back to array */
		array[i] = output[i];
	free(cnt_arr);
	free(output);
}
