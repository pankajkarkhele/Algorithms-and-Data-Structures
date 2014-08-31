//Suffix Array o(nlognlogn))

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100000
using namespace std;

typedef struct
{
	int index;
	int rank1, rank2;

}suffix;

bool comp (suffix a, suffix b)
{
	return (a.rank1 == b.rank1) ? (a.rank2 < b.rank2) : (a.rank1 < b.rank1);
}

suffix array[MAXN+1];

void build_sa (char *s, int len)
{
	for (int i = 0; i < len; ++i)
	{
		array[i].index = i;
		array[i].rank1 = (s[i] - 'a');
		array[i].rank2 = (i+1 < len) ? (s[i+1]-'a') : -1;
	}
	sort (array, array+len, comp);
	int ind[len];
	for (int k = 4; k < 2*len; k *= 2)
	{
		int rank1 = array[0].rank1 = 0;
		int prev_rank1 = array[0].rank1;
		ind[array[0].index] = 0;
		for (int i = 1; i < len; ++i)
		{
			if (array[i].rank1 == prev_rank1 && array[i].rank2 == array[i-1].rank2)
				prev_rank1 = array[i].rank1, array[i].rank1 = rank1;
			else
				prev_rank1 = array[i].rank1, array[i].rank1 = ++rank1;	
			ind[array[i].index] = i;	
		}
		for (int i = 0; i < len; i++)
        {
            int nextidx = array[i].index + k/2;
            array[i].rank2 = (nextidx < len)?
                                  array[ind[nextidx]].rank1: -1;
        }
		sort (array, array+len, comp);
	}	 
}

int main ()
{
	char s[] = "dssdfudsu";
	int len = strlen(s);
	build_sa(s, len);
	for (int i = 0; i < len; ++i)
		printf ("%d ", array[i].index);
	printf ("\n");	
	return 0;
}	
