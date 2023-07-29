#include "sort.h"

/**
* integer_swap - Function that swaps two integers
* @y: First integer to swap
* @z: Second integer to swap
*/
void integer_swap(int *y, int *z)
{
int wap;

wap = *y;
*y = *z;
*z = wap;
}

/**
* lomuto_partition - Function that implements the
* lomuto partition scheme
* @array: Array of in of integers
* @size: Size of array
* @start: Start of index
* @end: End of index
* Return: Partition index
*/

int lomuto_partition(int *array, size_t size, int start, int end)
{
int *pivot = array + end;
int maxx = start;
int minn = start;

while (minn < end)
{
if (array[minn] < *pivot)
{
if (maxx < minn)
{
integer_swap(array + minn, array + maxx);
print_array(array, size);
}
maxx++;
}
minn++;
}

if (array[maxx] > *pivot)
{
integer_swap(array + maxx, pivot);
print_array(array, size);
}

return (maxx);
}

/**
* sort_lomuto - Function that implement the quick
* sort algorithm
* @array: Array of integers to sort
* @size: The size of the array.
* @start: Start of index in array
* @end: End of index in array
*
* Description: Lomuto partition scheme implementation
*/

void sort_lomuto(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = lomuto_partition(array, size, start, end);
		sort_lomuto(array, size, start, part - 1);
		sort_lomuto(array, size, part + 1, end);
	}
}

/**
* quick_sort - Function that sorts an array of
* integers in ascending order using Quick sort
* algorithm
* @array: Array of integers
* @size: Array size
*
* Description: To print the array after each time you swap two elements
*/

void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

sort_lomuto(array, size, 0, size - 1);
}
