#include <stdio.h>
#include <time.h>
#include <stdlib.h>
	
	
int main(void)
{
	int f;
	int sum = 0;
	int n;
	srand(time(NULL));
	printf("GAME RULES: The game begins with the number 0.\n" 
	"During the course, you can add to the existing number\n"
	"any number from 1 to 10. The one, who reach the number \"100\", wins.\n\n");
	printf("Choose the game mode:\n1.PvE\n2.PvP\n");
	do{
		scanf("%d",&f);
	}while(f < 1 || f > 2);
	
	switch(f)
	{
	case 1:
	do{
		do{
			printf("Enter the number(1 - 10)\n");
			scanf("%d",&n);
		}while(n < 1 || n > 10);
			sum += n;
			printf("sum = %d\n\n",sum);
			if(sum >= 100)
			{
				printf("You win!\n");
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
				printf("sum = %d\n\n",sum);
				if(sum >= 100)
				{
					printf("You lose!\n");
				}
			}		
		}while(sum < 100);
		break;
		case 2:
			do{
				do{
					printf("Player1 step\n");
					scanf("%d",&n);
				}while(n < 1 || n > 10);
				sum += n;
				printf("sum = %d\n\n",sum);
			if(sum >= 100)
			{
				printf("Player1 win!\n");
			}
			else{

			do{
					printf("Player2 step\n");
					scanf("%d",&n);
				}while(n < 1 || n > 10);
				sum += n;
				printf("sum = %d\n\n",sum);
			if(sum >= 100)
			{
				printf("Player2 win!\n");
			}
		}
			}while(sum < 100);
			break;
	}
	
	}
