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
 * hoare_partition - order an array according to hoare partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: starting of the subset to order
 * @right: the ending of the subset to order
 * Return: final partition index
 */
size_t hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, i, j;

	pivot = array[left];
	i = left - 1;
	j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}

}

/**
 * hoare_sort - implement the quicksort algorith through recursion
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the array partition order
 * @right: ending index of the array partition scheme
 */
void hoare_sort(int *array, size_t size, size_t left, size_t right)
{
	int partition;

	if (left < right)
	{
		partition = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partition);
		hoare_sort(array, size, partition + 1, right);
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

	hoare_sort(array, size, 0, size - 1);
}
