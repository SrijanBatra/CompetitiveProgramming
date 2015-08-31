#include<stdio.h>
#include<stdlib.h>

long long sum;
long long max_modulo;
long long min_modulo;
long long set[100000 + 10];
long long powers[100000 + 10];


void calPower(long long power){
	if(power == 0){
		powers[0] = 1;
	}
	else{
		powers[power] = ((2 * ((powers[power-1])%(1000000000 + 7)))%(1000000000 + 7));
	}
}

void cal_min_sum(long long n){
	long long index;
	for(index = n-1; index >= 0; index-=1){
		long long contribution = ((((set[index])%(1000000000 + 7)) * ((powers[n-1-index])%(1000000000 + 7)))%(1000000000 + 7));
		min_modulo = (((min_modulo) + (contribution)));
	}
	
}

void cal_max_sum(long long n){
	long long index;
	for(index = 0; index < n; index+=1){
		calPower(index);
		long long contribution = ((((set[index])%(1000000000 + 7)) * ((powers[index])%(1000000000 + 7)))%(1000000000 + 7));
		max_modulo = (((max_modulo) + (contribution)));
	}	
}


static int cmpfunc (const void * a, const void * b)
{
    if( *(long long *)a - *(long long *)b < 0 )
        return -1;
    if( *(long long *)a - *(long long *)b > 0 )
        return 1;
    if( *(long long *)a - *(long long*)b == 0 )
        return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	int tn = 1;	
	long long n;
	while(tn <= T){
		long long index;
		scanf("%lld",&n);
		min_modulo = 0;
		max_modulo = 0;
		sum = 0;
		for(index = 0; index < n; index+=1){
			scanf("%lld",&set[index]);
		}

		qsort(set,n,sizeof(long long),cmpfunc);

		cal_max_sum(n);
		cal_min_sum(n);		

		sum = ((((max_modulo)%(1000000000 + 7)) - ((min_modulo)%(1000000000 + 7))));
		if(sum < 0){
			sum = sum + (1000000000 + 7);
		}
		printf("%lld\n",sum);
		tn+=1;
	}

	return 0;

}