#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *list, int len_list);
void swap(int *num1, int *num2);
void heap_insert(int *heap, int num, int cur_index);
int heap_delete(int *heap, int max_index, int start_index);

int main(void)
{
	int len_list, index;
	scanf("%d", &len_list);
	int *list = (int *) malloc(len_list * sizeof(int));
	for (index = 0; index < len_list; ++index)
		scanf("%d", &list[index]);
	heap_sort(list, len_list);	
	for (index = 0; index < len_list; ++index)
		printf("%d\n", list[index]);	
	return 0;
}	

void heap_sort(int *list, int len_list)
{
	int *heap = (int *) malloc(len_list * sizeof(int) + 2);
	int index, heap_index;
	heap_index = 1;
	for (index = 0; index < len_list; ++index)
		heap_insert(heap, list[index], heap_index), heap_index++;		
	for (index = len_list-1; index >= 0; --index)
		heap_index--, list[index] = heap_delete(heap, heap_index, 1);
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}	

void heap_insert(int *heap, int num, int cur_index)
{
	heap[cur_index] = num;
	int parent = cur_index/2;
	if ((parent > 0))
	{
		while ((heap[parent] < heap[cur_index]) && (parent > 0))
		{
			swap(&heap[parent], &heap[cur_index]);
			cur_index = parent;
			parent = cur_index/2;	
		}	
	}
}

int heap_delete(int *heap, int max_index, int start_index)
{
	swap(&heap[start_index], &heap[max_index]);
	int child1 = 2*start_index, child2 = child1+1;
	while (((heap[start_index] < heap[child1]) || (heap[start_index] < heap[child2])) && (child1 < max_index) && (child2 < max_index))
	{
		if ((heap[child2] < heap[child1]) && (child1 < max_index))
		{
			swap(&heap[start_index], &heap[child1]);
			start_index = child1;
			child1 = 2*start_index;
			child2 = child1+1;
		}
		else if ((heap[child1] < heap[child2]) && (child2 < max_index))
		{
			swap(&heap[start_index], &heap[child2]);
			start_index = child2;
			child2 = 2*start_index+1;
			child1 = child2-1;
		}
	}
	return heap[max_index]; 	
}
