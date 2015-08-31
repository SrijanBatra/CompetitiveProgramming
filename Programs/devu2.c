#include<stdio.h>
#include<stdlib.h>

int main(){
	long T;
	long tn = 1;
	scanf("%ld",&T);
	long n,k;
	while(tn <= T){
		scanf("%ld %ld",&n,&k);
		long i;
		int flag0 = 0, flag1 = 0;
		long counter = 0;
		long inversions = 0;
		int string[n];
		long number;
		scanf("%ld",&number);
		int current;
		int prev_inverted = 0;
		current = number%10;
		number = number/10;
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
			
			if(flag0 == 1){
				if(current == 1){
					flag0 = 0;
					flag1 = 1;
					counter = 1;
				}
				else{
					
					if(counter == k){
						if(prev_inverted == 0){
							string[i] = 1;
							flag0 = 0;
							flag1 = 1;
							inversions++;
							counter = 0;
							prev_inverted = 1;
						}
						else{
							string[i-k] = 1;
							string[i-k-1] = 0;
							string[i] = 0;
							counter = k-1;
							prev_inverted = 0;
						}
					}
					else{
						string[i] = 0;
					}
					
					counter += 1;
				}
			}

			else if(flag1 == 1){
				
				if(current == 0){
					flag0 = 1;
					flag1 = 0;
					counter = 1;
				}
				else{
					
					if(counter == k){
						if(prev_inverted == 0){
							string[i] = 0;
							flag0 = 1;
							flag1 = 0;
							inversions++;
							counter = 0;
							prev_inverted = 1;
						}
						else{
							string[i-k] = 0;
							string[i-k-1] = 1;
							string[i] = 1;
							counter = k-1;
							prev_inverted = 0;
						}
					}
					else{
						string[i] = 1;
					}
					
					counter += 1;
				}
			}
		}
		printf("\n%ld\n", inversions);
		//print string in reverse here.
		long index = 0;
		for(index = n-1;index >= 0;index--){
			printf("%d", string[index]);
		}
		printf("\n");
		tn++;	
	}
	return 0;
}