#include "sort.h"

/**
* _max_array_get - Function that get the maximum
* value in an array of integers
* @array: Array of integers
* @size: Size of the array
* Return: Max integer in array
*/

int _max_array_get(int *array, int size)
{
int get, i;
get = array[0];
i = 1;
while (i < size)
{
if (array[i] > get)
get = array[i];
i++;
}
return (get);
}

/**
* counting_sort - Function that sort an array of integers
* in an ascending order using the Counting sort algorithm
* @array: Array of integers
* @size: Array size
* Description: Prints the counting array once it is set up
*/

void counting_sort(int *array, size_t size)
{
int *count, *sorted, get, i;
if (array == NULL || size < 2)
return;
sorted = malloc(sizeof(int) * size);
if (sorted == NULL)
return;
get = _max_array_get(array, size);
count = malloc(sizeof(int) * (get + 1));
if (count == NULL)
{
free(sorted);
return;
}
i = 0;
while (i < (get + 1))
{
count[i] = 0;
i++;
}
i = 0;
while (i < (int)size)
{
count[array[i]] += 1;
i++;
}
i = 1;
while (i < (get + 1))
{
count[i] += count[i - 1];
i++;
}
print_array(count, get + 1);
i = 0;
while (i < (int)size)
{
sorted[count[array[i]] - 1] = array[i];
count[array[i]] -= 1;
i++;
}
i = 0;
while (i < (int)size)
{
array[i] = sorted[i];
i++;
}
free(sorted);
free(count);
}
