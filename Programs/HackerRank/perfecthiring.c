#include<stdio.h>
#include<stdlib.h>

int main(){
	long long N, P, X;
	long long A[100000 + 10];
	long long scores[100000 + 10];
	scanf("%lld %lld %lld", &N, &P, &X);
	long long index;
	long long maximum;
	for(index = 0; index < N; index ++){
		scanf("%lld", &A[index]);
	}
	maximum = 0;
	scores[0] = P * A[0];
	P = P - X;
	for(index = 1; index < N; index++){
		scores[index] = P * A[index];
		P = P - X;
		if(scores[index] > scores[maximum]){
			maximum = index;
		}

	}

	printf("%lld\n", maximum + 1);
	return 0;
}