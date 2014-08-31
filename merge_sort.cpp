//Merge Sort

#include <stdlib.h>
#include <stdio.h>

void merge(int *sorted, int *left, int lcount, int *right, int rcount);
void mergesort(int *array, int acount);

int main ()
{
	int t, i;
	scanf("%d", &t);
	int *array = (int *) malloc(t * sizeof(int));
	for (i = 0; i < t; ++i)
		scanf("%d", &array[i]);
	mergesort(array, t);
	for (i = 0; i < t; ++i)
		printf("%d\n", array[i]);
	free(array);		
	return 0;
}	

void merge(int *sorted, int *left, int lcount, int *right, int rcount)
{
	int i, j, k;
	i = 0, j = 0, k = 0;
	while (i < lcount && j < rcount)
	{
		if (left[i] < right[j])
			sorted[k++] = left[i++];
		else
			sorted[k++] = right[j++];
	}
	while (i < lcount)
		sorted[k++] = left[i++];
	while (j < rcount)
		sorted[k++] = right[j++];		
}

void mergesort(int *array, int acount)
{
	int i;
	if (acount < 2)
		return;
	int mid = acount/2;
	int *left = (int *) malloc(mid * sizeof(int));
	int *right = (int *) malloc((acount-mid) * sizeof(int));
	for (i = 0; i < mid; ++i)
		left[i] = array[i];
	for (i = mid; i < acount; ++i)
		right[i-mid] = array[i];
	mergesort(left, mid);
	mergesort(right, acount-mid);
	merge(array, left, mid, right, acount-mid);
	free(left);
	free(right);	
}
