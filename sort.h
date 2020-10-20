#ifndef SORT_H
#define SORT_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* STRUCTS AND DEFINITIONS */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* FUNCTION PROTOTYPES */
/* function to print array of integers */
void print_array(const int *array, size_t size);

/* function to print list of integers */
void print_list(const listint_t *list);

/* function to sort array of integers with bubble sort */
void bubble_sort(int *array, size_t size);

/* function to sort doubly linked list of integers with insertion sort */
void insertion_sort_list(listint_t **list);

/* function to sort array of integers with selection sort */
void selection_sort(int *array, size_t size);

/* function to sort array of integers with quick sort */
void quick_sort(int *array, size_t size);
void quick_sorting(int *array, size_t size, int *full_array, size_t full_size);

/* function to sort array of integers with shell sort */
void shell_sort(int *array, size_t size);

/* function to sort doubly linked list of integers with cocktail sort */
void cocktail_sort_list(listint_t **list);

/* function to sort array of integers with counting sort */
void counting_sort(int *array, size_t size);

/* function to sort array of integers with radix sort */
void radix_sort(int *array, size_t size);
int digit_counting(int *array, size_t size);
int divider_set(int current_digit);

#endif
