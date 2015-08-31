#include<stdio.h>
#include<stdlib.h>

long long P[100000 + 10];

int main(){
	long long N;
	scanf("%lld", &N);
	long long index = 0;
	while(index < N){
		scanf("%lld", &P[index]);
		index++;
	}

	int flag = 1;
	long long days = 0;
	long long lastValue;

	while(flag != 0){
		index = 1;
		lastValue = P[0];
		flag = 0;
		while(index < N){
			if(P[index] > lastValue){
				lastValue = P[index];
				P[index] = -1;
				flag = 1;
				while(P[index] == -1){
					index++;
				}
			}
			else if(P[index] != -1){
				lastValue = P[index];
				index++;
			}
			else
				index++;
			
		}
		if(flag == 1){
			days++;
		}
	}
	printf("%lld\n", days);
	return 0;
}