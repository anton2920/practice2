	#include<stdio.h>
	
	int main(void)
	{
		int sum = 0;
		int n;
		srand(time(NULL));
		do{
			do{
				printf("Enter the number(1 - 10)\n");
				scanf("%d",&n);
			}while(n < 1 || n > 10);
			sum += n;
			printf("sum = %d\n",sum);
			if(sum >= 100)
			{
				printf("You win!");
			}
			else
			{
				if(sum < 80)
				{	
					n = rand() % (10 - 1 + 1) + 1;
					printf("computer move: %d\n",n);
				}else if(sum >= 80 && sum < 90 && sum != 89){
					n = 90 - sum - 1;
					printf("computer move: %d\n",n);
				}else if(sum >= 90){
					n = 100 - sum;
					printf("computer move: %d\n",n);
				}else if(sum == 89){
					n = rand() % (10 - 1 + 1) + 1;
					printf("computer move: %d\n",n);
				}
				
				
				sum += n;
				printf("sum = %d\n",sum);
				if(sum >= 100)
				{
					printf("You lose!");
				}
			}
			
		}while(sum < 100);
	}