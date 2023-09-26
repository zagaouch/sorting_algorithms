#include "sort.h"

/**
 * bubble_sort - boubble fucntion to sort a list
 * @array : array list
 * @size : the size of the arraye
*/

void bubble_sort(int *array, size_t size)
{
int tmp;
size_t i, j;

if (array == NULL)
return;
for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - 1 - i; j++)
{
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
print_array(array, size);
}
}
}

}
