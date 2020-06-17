#include "sort.h"

/**
 * radix_sort - sorts an array of integers using LSD radix sort
 * array is sorted in ascending order
 * @array: given array to sort
 * @size: size of array to sort
 *
 */

void radix_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, k = 0;
	int *holder;
	int digit_count = 0, current_digit = 0, n = 0, m = 0, divider = 0;

	holder = malloc(sizeof(int) * size);
	if (holder == NULL)
		return;
	digit_count = digit_counting(array, size);
	while (current_digit < digit_count)
	{
		for (i = 0; i < size; i++)
		{
			divider = divider_set(current_digit);
			n = (array[i] / divider) % 10;
			if (i == 0)
				holder[i] = array[i];
			else
			{
				for (j = 0; j < i; j++)
				{
					m = (holder[j] / divider) % 10;
					if (m > n)
					{
						break;
					}
				}
				if (j != i)
				{
					for (k = i; k > j; k--)
						holder[k] = holder[k - 1];
				}
				holder[j] = array[i];
			}
		}
		for (j = 0; j < size; j++)
			array[j] = holder[j];
		current_digit++;
		print_array(array, size);
	}
	free(holder);
}

/**
 * digit_counting - counts how many digits are in ints
 * @array: input array of ints to count digits of
 * @size: size of input array
 *
 * Return: largest digit count of all ints in array
 */

int digit_counting(int *array, size_t size)
{
	unsigned int i = 0;
	int current_count = 0, max_count = 0, n = 0;

	for (i = 0; i < size; i++)
	{
		n = array[i];
		current_count = 1;
		while (n / 10 != 0)
		{
			current_count++;
			n /= 10;
		}
		if (current_count > max_count)
		{
			max_count = current_count;
		}
	}
	return (max_count);
}

/**
 * divider_set - uses cuurent_digit information to determine divider
 * @current_digit: current_digit
 *
 * Return: divider to access corresponding digit
 */

int divider_set(int current_digit)
{
	int i = 0, divider = 1;

	for (i = 0; i < current_digit; i++)
		divider *= 10;
	return (divider);
}
