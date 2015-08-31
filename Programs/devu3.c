#include<stdio.h>
#include<stdlib.h>

int string[100000 + 10];

long number;
long inversions;
long inversions2;
long i;
long counter;

int current;
int next;
int flag0 , flag1;
int prev_inverted = 0;

int scheme1(long n){	
	for(i = 0;i < n;i ++){
		current = number%10;
		number = number/10;
		if(current == 0){
			if(flag0 == 1){
				string[i] = 1;
				flag1 = 1;
				flag0 = 0;
				inversions++;
			}
			else{
				string[i] = 0;
				flag0 = 1;
				flag1 = 0;
				inversions2++;
			}
		}
		else{
			if(flag1 == 1){
				string[i] = 0;
				flag1 = 0;
				flag0 = 1;
				inversions++;
			}
			else{
				string[i] = 1;
				flag0 = 0;
				flag1 = 1;
				inversions2++;
			}
		}
	}
	if(inversions2 < inversions){
		return 1;
	}
	else
		return 0;
}

void scheme2(long n, long k){
	current = number%10;
	number = number/10;
	next = number%10;
	if(current == 0){
		flag0 = 1;
		counter = 1;
		string[0] = 0;
	}
	else if(current == 1){
		flag1 = 1;
		counter = 1;
		string[0] = 1;
	}
	for(i = 1;i < n;i ++){
		current = number%10;
		number = number/10;
		if(counter == k){

		}
	}
}

int main(){
	long T;
	long tn = 1;
	scanf("%ld",&T);
	long n,k;
	while(tn <= T){		
		scanf("%ld %ld",&n,&k);
		scanf("%ld",&number);

		flag0 = 0;
		flag1 = 0;
		counter = 0;		
		prev_inverted = 0;		
		inversions = 0;
		inversions2 = 0;
		int invert = 0;;

		if(k == 1)	{
			
			invert = scheme1(n);
		}
		else{
			scheme2(n, k);
		}

		printf("\n%ld\n", inversions);
		
		//print string in reverse here.
		long index = 0;
		if(invert == 1){
			flip(string[n-1]);
			for(index = n-1;index >= 0;index--){
				if(string[index] == 1)
					printf("0");
				else
					printf("1");
			}
		}
		else{
			for(index = n-1;index >= 0;index--){
				printf("%d", string[index]);
			}
		}
		printf("\n");
		tn++;
	}
}