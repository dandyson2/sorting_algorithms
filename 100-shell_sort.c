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
* shell_sort - Sort an array of integers in ascending
*              order using the shell sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Uses the Knuth interval sequence.
*/

void shell_sort(int *array, size_t size)
{
size_t gap, m, n;

if (array == NULL || size < 2)
return;

gap = 1;
while (gap < size / 3)
gap = gap * 3 + 1;

while (gap >= 1)
{
for (m = gap; m < size; m++)
{
n = m;
while (n >= gap && array[n - gap] > array[n])
{
integer_swap(array + n, array + (n - gap));
n -= gap;
}
}
print_array(array, size);
gap /= 3;
}
}
