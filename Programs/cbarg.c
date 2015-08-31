#include<stdio.h>
#include<stdlib.h>

long long memory[100000 + 10];

int main(){
	long long T;
	long long tn = 1;
	long long n;
	scanf("%lld", &T);
	while(tn <= T){
		scanf("%lld", &n);
		long long index;
		long long mem;
		long long tmemall, memall;
		scanf("%lld", &mem);
		tmemall = mem;
		memall = mem;
		for(index = 1; index < n; index++){
			scanf("%lld", &mem);
			if(mem > memall){
				tmemall += (mem - memall);
			}
			memall = mem;

		}

		printf("%lld\n", tmemall);
		tn++;
	}

	return 0;
}