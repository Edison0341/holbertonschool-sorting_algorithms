#include "sort.h"
/**
 * selection_sort - sorts an array of ints in ascending order
 * @array: list of integers
 * @size: number of elements
 */
void selection_sort(int *array, size_t size)
{
	size_t idx1, idx2, min;
	int *ptr1 = array, *ptr2 = array, swap;

	for (idx1 = 0; idx1 < size; idx1++)
	{
		min = idx1;
		for (idx2 = idx1 + 1; idx2 < size; idx2++)
		{
			if (ptr1[min] > ptr2[idx2])
				min = idx2;
		}
		if (min != idx1)
		{
			swap = ptr1[idx1];
			ptr1[idx1] = ptr2[min];
			ptr2[min] = swap;
			print_array(array, size);
		}
	}
}
