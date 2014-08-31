//Quicksort using frst element as pivot

#include <stdio.h>
#include <stdlib.h>

void quicksort(int *array, int start, int len);

int main ()
{
	int num, index;
	scanf ("%d", &num);
	int *array = (int *) malloc(num*sizeof(int));
	for (index = 0; index < num; ++index)
		scanf ("%d", &array[index]);
	quicksort(array, 0, num);	
	for (index = 0; index < num; ++index)
		printf ("%d\n", array[index]);
	return 0;
}

void quicksort(int *array, int start, int len)
{
	if (len-start < 2)
		return;
	int p, i, j, temp;
	p = start, i = start, j = i + 1;
	for (j; j < len; ++j)
	{
		if (array[j] <= array[p])
		{
			temp = array[i+1];
			array[i+1] = array[j];
			array[j] = temp;
			++i;
		}
	}
	temp = array[p];
	array[p] = array[i];
	array[i] = temp;
	quicksort(array, 0, p);
	quicksort(array, p+1, len);	
}
