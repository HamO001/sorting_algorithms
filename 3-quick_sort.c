#include "sort.h"
/**
 * swap_ints - waps two integers
 * @a: firts integer
 * @b: second integer
 * Return: Nothing
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lamuto_partition - order an array according to hoare partition scheme
 * @array: array of integers
 * @size: size of the array
 * @low: starting of the subset to order
 * @high: the ending of the subset to order
 * Return: final partition index
 */
size_t lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot_ptr, up, down;

	pivot_ptr = array + right;

	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot_ptr)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot_ptr)
	{
		swap_ints(array + up, pivot_ptr);
		print_array(array, size);
	}

	return (up);

}

/**
 * hoare_sort - implement the quicksort algorith through recursion
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the array partition order
 * @right: ending index of the array partition scheme
 */
void lomuto_sort(int *array, size_t size, size_t left, size_t right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - sort an array of integers in an ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
