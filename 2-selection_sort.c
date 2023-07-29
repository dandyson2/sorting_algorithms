#include "sort.h"

/**
* integer_swap - Function that swaps two integers in an array.
* @y: First integer
* @z: Second integer
*/
void integer_swap(int *y, int *z)
{
int wap;

wap = *y;
*y = *z;
*z = wap;
}

/**
* selection_sort - Function that sort an array of
* integers in ascending order using the selection
* sort algorithm
* @array: Array of integers
* @size: Size of the array
*
* Description: Print the array after each time you swap two elements
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
low = (array[n] < *low) ? (array + n) : low;
n++;
}

if ((array + m) != low)
{
integer_swap(array + m, low);
print_array(array, size);
}

m++;
}
}
