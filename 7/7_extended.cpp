#include <iostream>
#include <math.h>
#define N 255
int sum_Del(int a){
	int sum=1;
	for (int i=2;i<=round(sqrt(a));i++){
		if (a%i==0){
			sum+=i;
			sum+=a/i;
		}
	}
	return sum;
}
int main(){
	for (int i=2;i<=N;i++){	
		int prom=sum_Del(i);
		if (i==sum_Del(prom)){
			std::cout<<i<<' '<<prom<<'\n';
		}
	}
	return 0;
}
