#include<stdio.h>
#include<stdlib.h>

long long permutation[100000];
int main(){
	int T;
	int tn = 1;
	long long N;
	scanf("%d", &T);
	while(tn <= T){
		long long lp = 1;
		scanf("%lld", &N);
		long long rp = N;
		long long index = 1;
		//long long dN = N;
		while(index <= N){
			permutation[N - index] = rp;
			if(N - index > 0)
				permutation[N - index - 1] = lp;
			lp += 1;
			rp -= 1;
			index += 2;
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