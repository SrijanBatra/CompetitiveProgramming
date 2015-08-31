#include<stdio.h>
#include<stdlib.h>

long long boys[100000 + 10];
long long girls[100000 + 10];

static int cmpfunc (const void * a, const void * b)
{
    if( *(long long *)a - *(long long *)b < 0 )
        return -1;
    if( *(long long *)a - *(long long *)b > 0 )
        return 1;
    if( *(long long *)a - *(long long*)b == 0 )
        return 0;
}

long long countPairs(long long N, long long K){
	
	long long i = 0;
	long long j = 0;
	long long pairs = 0;
	while(i < N){
		
		if(girls[j] < boys[i]){
			
			if(boys[i] - girls[j] <= K){
				pairs ++;
				i++;
				j++;
			}

			else{
				j ++; 	//girl cannot be paired with any boy.
				if(j == N){
					return pairs;
				}
			}
		}
		
		else{
			if(girls[j] - boys[i] <= K){
				pairs ++;
				i++;
				j++;
			}

			else
				i ++;

		}
	}
	return pairs;
}

int main(){
	long long N, K;
	scanf("%lld %lld", &N, &K);


	long long pairs = 0;
	long long index;

	for(index = 0; index < N; index++){
		scanf("%lld", &boys[index]);
	}
	for(index = 0; index < N; index++){
		scanf("%lld", &girls[index]);
	}

	qsort(boys,N, sizeof(long long),cmpfunc);
	qsort(girls,N, sizeof(long long),cmpfunc);


	pairs = countPairs(N,K);

	printf("%lld\n", pairs);

	return 0;

}