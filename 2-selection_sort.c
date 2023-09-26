#include "sort.h"


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
		}
		/*Print array after each swap*/
		print_array(array, size);

	}
}
