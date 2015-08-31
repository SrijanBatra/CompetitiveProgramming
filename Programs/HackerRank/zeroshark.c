#include<stdio.h>
#include<stdlib.h>

long long array[100000-3 + 10];
//mod = 1000000007;

int main(){
	int T;
	scanf("%d",&T);
	int tn = 1;	
	long long n;
	long long mod = 1000000007;
	array[1] = 1;
	array[2] = 1;
	long long index;
	for(index = 3;index <= 1000000; index++){
		array[index] = array[index- 1] + array[index-2];
	}
	while(tn <= T){
		long long index;
		long long answer;
		scanf("%lld", &n);

		

		printf("%lld\n",array[n]%mod);
		tn++;
	}

	return 0;
}