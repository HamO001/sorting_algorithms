#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t min_index, i, j, temp;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;

		/*Find the minimum element in the unsorted portion of the array*/
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		/*Swap the min element with the first element in the unsorted portion*/
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
		/*Print array after each swap*/
		/*print_array(array, size);*/

	}
}
