#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 ** swap_ints - Swap two integers in an array.
 ** @a: The first integer to swap.
 ** @b: The second integer to swap.
 **/
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 ** lomuto_partition - Order a subset of an array of integers according to
 **                    the Lomuto partition scheme (last element as pivot).
 ** @array: The array of integers.
 ** @size: The size of the array.
 ** @low: The starting index of the subset to order.
 ** @high: The ending index of the subset to order.
 **
 ** Return: The final partition index.
 **/
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap_ints(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap_ints(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 ** lomuto_sort - Implement the quicksort algorithm through recursion.
 ** @array: An array of integers to sort.
 ** @size: The size of the array.
 ** @low: The starting index of the array partition to order.
 ** @high: The ending index of the array partition to order.
 **
 ** Description: Uses the Lomuto partition scheme.
 **/
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int partition;

	if (high - low > 0)
	{
		partition = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, partition - 1);
		lomuto_sort(array, size, partition + 1, high);
	}
}

/**
 ** quick_sort - Sort an array of integers in ascending
 **              order using the quicksort algorithm.
 ** @array: An array of integers.
 ** @size: The size of the array.
 **
 ** Description: Uses the Lomuto partition scheme. Prints
 **              the array after each swap of two elements.
 **/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
