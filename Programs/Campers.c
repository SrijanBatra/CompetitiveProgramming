#include<stdio.h>
#include<stdlib.h>

long long array[2000000];
long long snipers[2000000];

int main(){
	long long N, K;
	scanf("%lld %lld", &N, &K);
	long long index = 0;
	long long additional = 0;
	long long sniperIndex = 0;
	long long sniperID;


	scanf("%lld", &sniperID);
	if(sniperID > 1){
		snipers[sniperID - 2] = 1;
	}
	snipers[sniperID - 1] = 1;
	snipers[sniperID] = 1;
	sniperIndex++;

	while(sniperIndex < K){
		scanf("%lld", &sniperID);
		if(sniperID > 1){
			snipers[sniperID - 2] = 1;
		}
		snipers[sniperID - 1] = 1;
		snipers[sniperID] = 1;
		sniperIndex++;
	}
	
	while(index < N){
		if(snipers[index] == 1){
			index++;
		}
		else{
			additional ++;
			index += 2;
		}
	}

	long long answer = K + additional;
	printf("%lld\n", answer);
}