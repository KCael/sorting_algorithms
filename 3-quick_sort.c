#include "sort.h"

/**
 * quick_sort - sort an array of ints in ascending order (QuickSort)
 * @array: array of integers
 * @size: number of elements in array
 *
 * Description: implementing Lomuto partition scheme
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicker_sort(array, size, 0, size - 1);
}

/**
 * quicker_sort - does the actual recursive QuickSort
 * @array: array of integers
 * @size: number of elements in array
 * @l: first index of array
 * @h: last index of array
 *
 * Description: Sorts the array quicker
 * Return: 0
 */
void quicker_sort(int *array, size_t size, int l, int h)
{
	int middle;

	if (l < h)
	{
		middle = partition(array, size, l, h);
		quicker_sort(array, size, l, middle - 1);
		quicker_sort(array, size, middle + 1, h);
	}
}

/**
 * partition - partition through an array of integers
 * @array: array of integers
 * @size: number of elements of array
 * @l: first index of array
 * @h: last index of array
 *
 * Description: all values must be accurate
 * Return: new index position
 */
int partition(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = 1, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - swaps elements in a given array
 * @ptr_a: the first argument
 * @ptr_b: second argument
 * Return: void
 *
 */
void swap(int *ptr_a, int *ptr_b)
{
	int temp;

	if (!ptr_a || !ptr_b)
		return;

	temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp;
}
