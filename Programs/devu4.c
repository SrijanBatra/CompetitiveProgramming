#include<stdio.h>
#include<stdlib.h>

char string[100000 + 10];
char newstring[100000 + 10];
long n,k;
int flag0,flag1;
long inversions;
long inversions2;
int scheme1(){
	
	long i;	
	for(i = 0;i < n;i ++){
		
		if(string[i] == '0'){
			if(flag0 == 1){
				flag1 = 1;
				flag0 = 0;
				inversions++;
				newstring[i] = 1;
			}
			else{
				flag0 = 1;
				flag1 = 0;
				inversions2++;
			}
		}
		else{
			if(flag1 == 1){
				flag1 = 0;
				flag0 = 1;
				inversions++;
				newstring[i] = 1;
			}
			else{
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

void scheme2(){
	long i;	
	long counter = 1;
	if(string[0] == '0'){
		flag0 = 1;
		flag1 = 0;
	}
	else{
		flag1 = 1;
		flag0 = 0;
	}

	for(i = 1;i < n;i ++){
		counter ++;
		if(flag0 == 1){
			if(string[i] == '0'){
				if(counter == k+1){
					if(string[i + 1] == '0'){
						newstring[i] = 1;		//next bit same as current one. last bit in sequence inverted.
						counter = 0;
						flag0 = 1;
						flag1 = 0;
					}
					else{
						newstring[i-1] = 1;
						counter = 1;
						flag1 = 0;
						flag0 = 1;
					}

					inversions++;
				}
			}
			else{
				counter = 1;
				flag1 = 1;
				flag0 = 0;
			}
		}

		//flag1 = 1:
		else{
			if(string[i] == '1'){		
				if(counter == k+1){
					if(string[i + 1] == '1'){
						newstring[i] = 1;	//next bit same as current one. last bit in sequence inverted.
						counter = 0;
						flag1 = 1;
						flag0 = 0;
					}
					else{
						newstring[i-1] = 1;
						counter = 1;
						flag0 = 0;
						flag1 = 1;
					}

					inversions++;
				}
			}
			else{
				counter = 1;
				flag1 = 0;
				flag0 = 1;				

			}
		}

	}	
}


int main(){
	long T;
	long tn = 1;
	long index;
	scanf("%ld",&T);
	int invert;
	while(tn <= T){
		scanf("%ld %ld",&n,&k);
		scanf("%s",string);

		inversions = 0;
		inversions2 = 0;
		invert = 0;
		for(index = 0; index < n; index++){
			newstring[index] = 0;
		}

		flag0 = 0;
		flag1 = 0;		

		if(k == 1){
			invert = scheme1();
		}
		else{
			scheme2();
		}
		
		if(invert == 0){
			printf("%ld\n", inversions);
			//Straight printing.
			for(index = 0;index < n;index++){
				if(newstring[index] == 0){
					if(string[index] == '1')
						printf("1");
					else
						printf("0");
				}
				else{
					if(string[index] == '1')
						printf("0");
					else
						printf("1");
				}
			}
		}
		
		else{
			//inverted printing.
			printf("%ld\n", inversions2);
			for(index = 0;index < n;index++){
				if(newstring[index] == 1){
					if(string[index] == '1')
						printf("1");
					else
						printf("0");
				}
				else{
					if(string[index] == '1')
						printf("0");
					else
						printf("1");
				}
			}
		}
		printf("\n");
		tn ++;
	}

	return 0;

}