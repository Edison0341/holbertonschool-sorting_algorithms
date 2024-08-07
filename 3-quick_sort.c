#include "sort.h"
#include <stdlib.h>
/**
 * swap- changes two values in an array
 * @array: list of integers'
 * @a: first swap value
 * @b:second swap value
 * @size: amount of element in the array
 */
void swap(int *array, int a, int b, int size)
{
	int shfl;

	if (array[a] != array[b])
	{
		shfl = array[a];
		array[a] = array[b];
		array[b] = shfl;
		print_array(array, size);
	}
}
/**
 * partition - sort the smaller array given by the parent function
 * @array: list of integers
 * @min: number of minimun index
 * @max: number of maximum index
 * @size: amount of elemets in the array
 * Return: index of the given pivot point
 */
int partition(int *array, int min, int max, size_t size)
{
	int idx1 = min, idx2;

	for (idx2 = min; idx2 < max; idx2++)
	{
		if (array[idx2] < array[max])
		{
			swap(array, idx1, idx2, size);
			idx1++;
		}
	}
	swap(array, idx1, max, size);
	return (idx1);
}
/**
 * quicksort - sort an array of integers in ascending order
 * @array: list of integers
 * @min: number of minimun index
 * @max: number of maximum index
 * @size: number of elements in the array
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int part;

	if (min < max)
	{
		part = partition(array, min, max, size);
		quicksort(array, min, part - 1, size);
		quicksort(array, part + 1, max, size);
	}
}
/**
 * quick_sort - sort an array of integers in ascending order
 * @array: list of integers
 * @size: number oe elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
