#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#define N 25
int check1(int a[N], int m, int x[N]);
int check2(int a1[][N], int x1[][N], int m, int n);
void key2(int a1[][N], int m, int n, int x1[][N]);
void key1(int a[N], int x[N], int m);
void rand2(int a1[][N], int m, int n, int x1[][N]);
void rand1(int a[N], int m, int x[N]);
void output2(int a1[][N], int m, int n);
void output1(int a[N], int m);
int task1(int a[N], int m, int x[N]);
int task2(int a1[][N], int m, int n, int x1[][N]);
int main()
{
	int x[N],x1[N][N],a[N],a1[N][N],m,f,l,d,n;
		printf("choose one or two-dimensional array ");
		do
		{
			scanf("%d", &d);
			if (d < 1 || d>2)
				printf("The incorrect value is entered.Try again ");
		} while (d < 1 || d>2);
		printf("Enter the array size?(up to 25) ");
		if (d == 1)
		{
			do {
				scanf("%d", &m);
				if (m < 2 || m>25)
					printf("The incorrect value is entered.Try again ");
			} while (m < 2 || m>25);
		}
		else
		{
			do {
				scanf("%d%d", &m, &n);
				if ((m < 2 || m>25) && (n < 2 || n>25))
					printf("The incorrect value is entered.Try again ");
			} while ((m < 2 || m>25) && (n < 2 || n>25));
		}
		printf("To fill the array from the keyboard(1) or it is random(2)? ");
		do {
			scanf("%d", &f);
			if (f < 1 || f>2)
				printf("The incorrect value is entered.Try again ");
		} while (f < 1 || f>2);
		l = d + f;
		if (d == 2 && f == 1) l = 5;
		switch (l)
		{
		case 2:key1(a, x, m); output1(a, m); task1(a,m,x); printf("\n"); output1(a, m); break;
		case 3:rand1(a,m,x); output1(a, m); task1(a, m, x); printf("\n"); output1(a, m); break;
		case 5:key2(a1, m, n, x1); output2(a1, m, n); task2(a1, m, n, x1); printf("\n"); output2(a1, m, n); break;
		case 4:rand2(a1, m, n, x1); output2(a1, m, n); task2(a1, m, n, x1); printf("\n"); output2(a1, m, n); break;
		}
	
		printf("\n");

		return 0;
}
int check1(int a[N], int m, int x[N])
{
	for (int i = 0; i < m; i++)
		if (x[i] == a[i])
			return (task1(a, m, x));
	return 1;
}
int check2(int a1[][N], int x1[][N], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x1[i][j] == a1[i][j])
				return (task2(a1, m, n, x1));
	return 1;
}
void key2(int a1[][N], int m, int n, int x1[][N])
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			printf(" a[%d;%d]= ", i, j);
			scanf("%d", &a1[i][j]);
			x1[i][j] = a1[i][j];
		}


}
void key1(int a[N], int x[N], int m)
{
	for (int i = 0; i < m; i++)
	{
		printf(" a[%d]= ", i);
		scanf("%d", &a[i]);
		x[i] = a[i];
	}

}
void rand2(int a1[][N], int m, int n, int x1[][N])
{
	int A, B;
	srand(time(NULL));
	do
	{
		printf("Enter an interval of random values [a,b] ");
		scanf("%d%d", &A, &B);
	} while (A > B);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a1[i][j] = rand() % (B - A + 1) + A;
			x1[i][j] = a1[i][j];
		}

}
void rand1(int a[N], int m, int x[N])
{
	int A, B;
	srand(time(NULL));
	do
	{
		printf("Enter an interval of random values [a,b] ");
		scanf("%d%d", &A, &B);
	} while (A > B);
	for (int i = 0; i < m; i++)
	{
		a[i] = rand() % (B - A + 1) + A;
		x[i] = a[i];
	}

}
void output2(int a1[][N], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d\t", a1[i][j]);
		printf("\n");
	}
}
void output1(int a[N], int m)
{
	for (int i = 0; i < m; i++)
		printf("%d\t", a[i]);
}
int task1(int a[N], int m, int x[N])
{
	int y;
	for (int i = 0; i < m; i++)
	{
		int g = rand() % m ;
		y = a[g];
		a[g] = a[i] ;
		a[i] = y;
	}
	check1(a, m, x);
	return 1;
}
int task2(int a1[][N], int m, int n, int x1[][N])
{
	int y;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int g = rand() % m ;
			int h = rand() % n ;
			y=a1[i][j] ;
			a1[i][j] =  a1[g][h];
			a1[g][h] = y;
		}
	check2(a1, x1, m, n);
	return 1;
}
