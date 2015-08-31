#include<stdio.h>
#include<stdlib.h>

int f[100000 + 10];
int is_invited[100000 + 10];
long long r[100000 + 10];
long long profit;
/*
int check(int index, long long value){
	
	value += r[index];
	if(is_invited[index] == 1 && value > 0){
		is_invited[index] = 2;
		return 1;
	}
	else{
		is_invited[index] = 1;
		int invite;
		invite = check(f[index], value);
		if(invite == 1){
			return 1;
		}
		else{
			is_invited[index] = 0;
			return -1;
		}
	}


}
*/
int check(int index, long long value){
	value += r[index];
	if(value < 0) return -1;
	if(is_invited[index] == 2 && value > 0){
		return 1;
	}
	else if(is_invited[index] == 1 && value > 0){
		is_invited[index] = 2;
		return 1;
	}
	
	else {
		is_invited[index] = 1;
		//value += r[index];
		int invite;
		invite = check(f[index], value);
		if(invite == 1){
			is_invited[index] = 2;
			return 1;
		}
		else{
			is_invited[index] = 0;
			return -1;
		}
	}
}
int main(){
	long T;
	long tn;
	scanf("%ld",&T);
	long n;
	long long value;
	int invite;
	int index;
	for(tn = 1; tn <= T; tn ++){
		scanf("%ld",&n);
		for(index = 1; index <= n; index+=1){
			scanf("%d",&f[index]);
		}
		for(index = 1; index <= n; index+=1){
			scanf("%lld",&r[index]);
		}
		for(index = 1; index <= n; index+=1){
			is_invited[index] = 0;
		}

		value = 0;
		profit = 0;
		for(index = 1; index<= n; index++){
			
			if(is_invited[index] == 2){		//2 meaning confirmed, 1 meaning under consideration. 0 meaning check it.
				profit += r[index];
			}
			else{
				if((invite = check(index,0)) == 1){
					is_invited[index] = 2;
					profit += r[index];
				}
			}

		}
		if(profit >= 0){
			printf("%lld\n", profit);
		}
		else
			printf("0\n");
	}

	return 1;
}