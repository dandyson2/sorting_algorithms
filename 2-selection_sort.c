#include "sort.h"

/**
 * integer_swap - Function that swaps two integers
 * in an array
 * @y: First integer
 * @z: Second integer
 */

void integer_swap(int *y, int *z)
{
	int tmp;

	tmp = *y;
	*y = *z;
	*z = tmp;
}

/**
 * selection_sort - Function that sorts an array
 * of integers in ascending order using the Selection sort algorithm
 * @array: The integer arrays
 * @size: The array size.
 */

void selection_sort(int *array, size_t size)
{
	int *low;
	size_t m = 0, n;

	if (array == NULL || size < 2)
		return;

	while (m < size - 1)
	{
		low = array + m;
		n = m + 1;

		while (n < size)
		{
			if (array[n] < *low)
				low = array + n;
			n++;
		}

		if ((array + m) != low)
		{
			integer_swap(array + m, low)
			print_array(array, size);
		}

		m++;
	}
}
