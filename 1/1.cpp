#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifdef _WIN32
	#define CLEAR ("cls")
#endif

#ifdef __unix__
	#define CLEAR ("clear")
#endif

const int m = 100, k=200;

void read_M_N(int *p_M, int *p_N)
{
	do
	{
		printf("M = "); scanf("%d", p_M);
	} while ((*p_M > m) || (*p_M < 1));
	do
	{
		printf("N = "); scanf("%d", p_N);
	} while ((*p_N > m) || (*p_N < 1));
}

void read(int a[m], int b[m], int M, int N)
{
	for (int i = 0; i < M; i++)
	{
			printf("\n a[%d] = ", i);
			scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++)
	{
		printf("\n b[%d] = ", i);
		scanf("%d", &b[i]);
	}
}

int new_array_similar(int a[m], int b[m], int M, int N, int new_arrey[k], int K)
{
	int help=INT_MIN;
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (a[i] == b[j]) {
				K++;
				new_arrey[K] = a[i];
				b[j] = help;
			}
		}
	if (K == -1) { K = -2; }
	return K;
}

int new_array_different(int a[m], int b[m], int M, int N, int new_arrey[k], int K)
{
	int count;
	
	for (int i = 0; i < M; i++)
	{
		count = 0;
		for (int j = 0; j < N; j++)
		{
			if (a[i] != b[j])
			{
				count++;
			}
		}
		if (count == N)
		{
			K++;
			new_arrey[K] = a[i];
		}
	}
	
	for (int j = 0; j < N; j++)
	{
		count = 0;
		for (int i = 0; i < M; i++)
		{
			if (a[i] != b[j])
			{
				count++;
			}
		}
		if (count == M)
		{
			K++;
			new_arrey[K] = b[j];
		}
	}
	
	return K;
}

void end_new(int new_arrey[k], int K)
{
	for (int i = 0; i < K; i++)
		printf(" new array[%d] = %d \n", i, new_arrey[i]);
	if (K == 0) printf(" Arrays are the same \n");
	if (K == -1) printf(" No identical elements \n");
}

int main()
{
	int a[m], b[m], new_arrey[k], K = -1, M, N, option;

	read_M_N(&M, &N);
	read(a, b, M, N);

	do {
		system(CLEAR);
		printf("Two arrays are given. Form a third array consisting of those elements that: \n 1) are present in both arrays; \n 2) are present only in one of the arrays. \n selected option: ");
		scanf("%d", &option);	
	} while ((option > 2) || (option < 1));

	switch (option)
	{
	case 1: {K = new_array_similar(a, b, M, N, new_arrey, K) + 1; } break;
	case 2: {K = new_array_different(a, b, M, N, new_arrey, K) + 1; } break;
	}
	
	end_new(new_arrey, K);

	return 0;
}
