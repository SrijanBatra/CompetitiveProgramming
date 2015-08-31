#include<stdio.h>
#include<stdlib.h>

int main(){
	long long N;
	long long number;
	long long index = 1;
	scanf("%lld", &N);
	for(index = 1; index <= N; index++){
		scanf("%lld", &number);
		
		long long count = 0;
		long long answer = number;
		while(number % 10 == 0){
			number /= 10;
		}
		
		while(number % 5 == 0){
			number = number/5;
			count++;
		}
		long long i = 0;
		while(i < count){
			answer *= 2;
			i++;
		}
		if(count % 2 != 0){
			answer *= 2;
		}

		printf("%lld\n", answer);
	}


	return 0;
}