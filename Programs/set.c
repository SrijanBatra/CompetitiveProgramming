#include<stdio.h>
#include<stdlib.h>

long long set[100000 + 10];
long long setDiff[100000 + 10];
long long sum;

int cmpfunc (const void *a, const void *b){
	return ( *(long long*)a - *(long long*)b);
}

void SumWithMod(long long add){
	sum = ((sum%(1000000000 + 7) + add%(1000000000 + 7))%(1000000000 + 7));
}

void include(long long maxIndex,long long min,long long n){
	long long max = set[maxIndex];
	SumWithMod(set[maxIndex] - set[min]);
	computeAll(maxIndex + 1, min, n);
}

void not_include(long long maxIndex,long long min,long long n){
	computeAll(maxIndex + 1,min, n);
}

void computeAll(long long index,long long minimum,long long n){
	long long i;
	long long current_minimum = minimum;
	for(i = index;i < n; i++){
		include(i,current_minimum,n);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	int tn = 1;	
	long long n;
	set[0] = 0;
	while(tn <= T){
		sum = 0;
		long long index;
		scanf("%lld",&n);
		for(index = 1; index < n; index++){
			scanf("%lld",&set[index]);
		}

		qsort(set,n,sizeof(long long),cmpfunc);
		for(index = 0; index < n - 1; index++){
			computeAll(index + 1,index,n);
		}
		//computeAll(1,1,n);
		printf("%lld\n",sum);
		tn++;
	}

	return 0;
 }