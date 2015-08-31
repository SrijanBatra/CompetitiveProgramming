#include<stdio.h>
#include<stdlib.h>



int main(){
	int T;
	scanf("%d",&T);
	int tn = 1;	
	long long n;
	long long n2;
	int days;
	while(tn <= T){
		long long index;
		scanf("%lld %d",&n, &days);
		for(index = 1; index <= days; index++){
			n = n/2;
			if(n > 3){
				n = 3*(n/4);
			}
		}

		printf("%lld\n", n);
		tn++;
	}

	return 0;
}