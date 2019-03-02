#include<stdio.h>

#define n 100

int main(void){	
	int k;
	int i,j,sum,f = 0;
	double p = 1;
	int a[n];
	
	do{
		printf("Enter the number of elements\n");
		scanf("%d",&k);
	}while(k < 1 || k > n);
	
	
	printf("Enter the array\n");
	for(i = 0; i < k; i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(j = 0; j < k; j++)
	{
		sum = 0;
		for(i = f; i < k; i++)
		{
			sum += a[i];
		}
		p *= sum;
		f++;
	}
	
	printf("Answer = %.0lf\n",p);
}
