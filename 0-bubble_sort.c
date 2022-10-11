#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	int swap = 0;
	size_t i = 0, j = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j + 1];
				array[j + 1] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
}
