#include<stdio.h>
#include<stdlib.h>
#include<math.h>


long long HCF2(long long num1,long long num2){
	long long temp;
	while(num2){
		temp = num1%num2;
		num1 = num2;
		num2 = temp;
	}
	return num1;
}


void check(long long no1,long long no2){
	long long hcf = HCF2(no1,no2);
	//int rs; 
	if(hcf == no2 ) printf("Yes\n");
	else{
		if(hcf == 1) printf("No\n");
		else{ 
			check(hcf,no2/hcf);
		}
	}
}

int main(){
	long T;
	long tn = 1;
	scanf("%ld",&T);
	while(tn <= T){
		long long no1, no2;
		scanf("%lld %lld",&no1,&no2);
		if(no1 == no2){
			printf("Yes\n");
		}
		else{
			check(no1,no2);
		}
		tn += 1;
	}
	return 0;
}