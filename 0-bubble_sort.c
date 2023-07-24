#include "sort.h"

/**
* integers_swap - Function that swaps two integers
* @y: First integer
* @z: Second integer
*/
void integers_swap(int *y, int *z)
{
int tmp;

tmp = *y;
*y = *z;
*z = tmp;
}

/**
* bubble_sort - Function that sorts an array of
* integers in ascending order
* @array: The integer array to sort
* @size: The array size
*
* Description: Prints the array after each swap.
*/

void bubble_sort(int *array, size_t size)
{
size_t i, len = size;
bool bubbly;

if (array == NULL || size < 2)
return;

do {
bubbly = false;
i = 0;
while (i < len - 1)
{
if (array[i] > array[i + 1])
{
integers_swap(array + i, array + i + 1);
print_array(array, size);
bubbly = true;
}
i++;
}
len--;
} while (bubbly);
}
