#include "sort.h"
#include <stdio.h>

/**
 * swap - utility function to swap to integers
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - The main
 * assumes that everything
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @idx: index
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;		
	int left = 2 * idx + 1;	
	int right = 2 * idx + 2; 

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if needed*/
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  The 
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;
	/**
	 * Start from bottommost
     * internal modes in bottom up way
	 */
	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	/**
	* Repeat follow
	*/
	for (i = (size - 1); i > 0; --i)
	{
		/**
		* The largest 
		*it with the las
		*size of heap by 1.
		*/
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Finally, heapify the root of tree.*/
		maxHeapify(array, size, 0, i);
	}
}
