#include<stdio.h>
#include<stdlib.h>


int main(){
	int T;
	long long N;
	long long K;
	scanf("%d",&T);
	int tn = 1;
	long long array[1000000 + 10];
	while(tn <= T){
		scanf("%lld %lld", &N, &K);
		long long days = 1;
		long long eaten;
		long long inpacket = K;
		long long packets = 1;
		long long temp;

		while(days <= N){
			scanf("%lld", &eaten);
			if(inpacket > eaten){
				inpacket -= (eaten + 1);
			}

			else if(inpacket < eaten){
				temp = (eaten - inpacket)%K;
				packets += (eaten - inpacket)/K;
				

				
				if(temp != 0){
					packets += 1;
					inpacket = K - temp;
					inpacket -= 1;
				}
				else
					inpacket = 0;
				
				
			}
			else
				inpacket = 0;

			days++;
		}
		printf("%lld\n", packets);

		tn++;
	}

	return 0;
}