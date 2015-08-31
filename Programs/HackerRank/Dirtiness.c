#include<stdio.h>
#include<stdlib.h>


int main(){
	int T;
	scanf("%d", &T);
	int tn = 1;
	long long N, M;
	while(tn <= T){
		scanf("%lld %lld", &N, &M);
		long long dirtiness;



		long long remainder = M % N;
		long long toiletNo;
		
		if(M % 2 == 0){
			dirtiness = (M - 1)/N;
			toiletNo = N - (((M - 1) % N))/2;
			
		}
		else{
			dirtiness = (M - 1)/N;
			toiletNo = ((M - 1) % N)/2 + 1;
            //if(toiletNo == 0)
                //toiletNo = 1;
			
		}
		
		printf("%lld %lld\n", toiletNo,dirtiness);
		tn++;
	}

	return 0;
}
