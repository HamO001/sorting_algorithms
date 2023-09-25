#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - function to sort integers using buble sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j, temp, k;

	if (array ==  NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*wap elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				/*print array after swap*/
				for (k = 0; k < size; k++)
				{
					printf("%d ", array[k]);
				}
				printf("\n");
			}
		}

		/*if no swap occured in this pass, the array is already sorted*/
		if (swapped == 0)
			break;
	}

}
