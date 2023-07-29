#include "sort.h"

/**
* integer_swap - Function that swaps two integersin an array
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
* heap_sorting - Function that transforms a binary
* tree into a binary heap
* @array: Array of integers rep a binary tree
* @size: Array size
* @link: The index of base
* @source: The root node
*/

void heap_sorting(int *array, size_t size, size_t link, size_t source)
{
size_t first, second, maxx;

first = 2 * source + 1;
second = 2 * source + 2;
maxx = source;

if (first < link && array[first] > array[maxx])
maxx = first;
if (second < link && array[second] > array[maxx])
maxx = second;

if (maxx != source)
{
integer_swap(array + source, array + maxx);
print_array(array, size);
heap_sorting(array, size, link, maxx);
}
}

/**
* heap_sort - Function that sorts an array of integers
* in ascending order using Heap sort algorithm
* @array: Array of integers
* @size: Size of the array
* Description: Print the array after each time you swap two elements.
*/

void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

i = (size / 2) - 1;
while (i >= 0)
{
heap_sorting(array, size, size, i);
i--;
}

i = size - 1;
while (i > 0)
{
integer_swap(array, array + i);
print_array(array, size);
heap_sorting(array, size, i, 0);
i--;
}
}
