#include<stdio.h>
#include<stdlib.h>

long long permutation[100000];
int main(){
	int T;
	int tn = 1;
	long long N;
	scanf("%d", &T);
	while(tn <= T){
		long long index = 1;
		scanf("%lld", &N);
		long long dN = N;
		while(index < dN){
			permutation[N - index] = dN;
			permutation[N - index - 1] = index;
			index++;
			dN--;
		}

		index = 0;
		printf("\n");
		while(index < N){
			printf("%lld ", permutation[index]);
			index++;
		}
		tn++;
	}

	return 0;
}