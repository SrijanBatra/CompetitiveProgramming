#include<stdio.h>
#include<stdlib.h>

long long array[3000 + 10];
long long sums[3000 + 10][3000 + 10];
//x = gap. y = starting point.
long long maximum = 0;

void initialize(long long n){
	long long i, j;
	
	for(j = n-1; j >= 1; j--){
		sums[1][j] = array[j] * array[j+1];
		if(sums[1][j] > maximum)
			maximum = sums[1][j];
	}		
	for(i = 2; i <= n/2; i--){		//gap interval
		for(j = n-i; j >= 1; j--){
			sums[i][j] =  sums[i-1][j + 1] + array[j - 1] * array[j- 1 + 2*(i-1)];
			if(sums[i][j] > maximum)
				maximum = sums[i][j];
		}						//starting point
	}

}


int main(){
	long long N;
	scanf("%lld", &N);
	long long index;
	for(index = 1; index <= N; index++){
		scanf("%lld", &array[index]);
	}
	initialize(N);
	printf("%lld\n", maximum);

}