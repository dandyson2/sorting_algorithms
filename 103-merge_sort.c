#include "sort.h"

/**
* merge_sort_arr - Function that sort a subarray of integers
* @sorting: Subarray of array of integers
* @buff: Buffer to store sorted array
* @first: First index of array
* @second: Second index of array
* @third: Third index of array
*/

void merge_sort_arr(int *sorting, int *buff, size_t first, size_t second,
size_t third)
{
size_t a = first, b = second, c = 0;

printf("Merging...\n[left]: ");
print_array(sorting + first, second - first);

printf("[right]: ");
print_array(sorting + second, third - second);

while (a < second && b < third)
{
buff[c++] = (sorting[a] < sorting[b]) ? sorting[a++] : sorting[b++];
}
while (a < second)
{
buff[c++] = sorting[a++];
}
while (b < third)
{
buff[c++] = sorting[b++];
}

a = first;
c = 0;
while (a < third)
{
sorting[a++] = buff[c++];
}

printf("[Done]: ");
print_array(sorting + first, third - first);
}

/**
* merge_sort_dupp - Function that implements the merge sort
* algorithm using recursion
* @sorting: Subarray of array of integers
* @buff: Buffer for storing sorted array
* @first: First index in subarray
* @third: Third index in subarray
*/

void merge_sort_dupp(int *sorting, int *buff, size_t first, size_t third)
{
size_t second;

if (third - first > 1)
{
second = first + (third - first) / 2;
merge_sort_dupp(sorting, buff, first, second);
merge_sort_dupp(sorting, buff, second, third);
merge_sort_arr(sorting, buff, first, second, third);
}
}

/**
* merge_sort - Function that sorts an array of integers
* in ascending order using Merge sort algorithm
* @array: Array of integers
* @size: Size of array
* Description: Implements the top-down merge sort algorithm.
*/

void merge_sort(int *array, size_t size)
{
int *buff;

if (array == NULL || size < 2)
return;

buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

merge_sort_dupp(array, buff, 0, size);

free(buff);
}
