#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int primeFactors(long long no1,long long no2){
	if(no2 % 2 == 0){
		if (no1 % 2 != 0){
			return 0;
		}
		else{
			while(no2 % 2 == 0){	
				no2 = no2/2;
			}
		}
	}

	long long i;
	for(i = 3; i <= (long long)sqrt(no2); i+=2){
		if(no2 % i == 0){
			if (no1 % i != 0){
				return 0;
			}
			else{
				while(no2 % i == 0){
					no2 = no2/i;
				}
			}
		}	
	}

	if(no2 > 2){
		if(no1 % no2 != 0){
			return 0;
		}
	}

	return 1;
}

int main(){
	long T;
	long tn = 1;
	scanf("%ld",&T);
	int rs;
	while(tn <= T){
		long long no1, no2;
		scanf("%lld %lld",&no1,&no2);
		if(no1 == no2){
			printf("Yes\n");
		}
		else{
			rs = primeFactors(no1,no2);
			if(rs == 1)
				printf("Yes\n");
			else printf("No\n");
		}
		tn += 1;
	}
	return 0;
}