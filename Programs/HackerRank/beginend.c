#include<stdio.h>
#include<stdlib.h>

int main(){
	long long N;	
	scanf("%lld", &N);
	char string[N + 10];
	scanf("%s", string);
	
	long long instances[200];
	long long answer = 0;
	long long i;
	
	
	int index = 97;
	for(index = 97; index <= 122; index++){
		instances[index] = 0;
	}

	for(i = 0; i <= N - 1; i++){
		//printf("\n%d\n", string[i]);
		instances[string[i]]++;
	}
	
	long long insts;
	for(index = 97; index <= 122; index++){
		insts = instances[index];
		if(insts != 0){
			answer += ( (insts * (insts + 1))/2 );
		}
	}
	
	
	printf("%lld\n", answer);
	
	return 0;
}