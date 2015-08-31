#include<stdio.h>
#include<stdlib.h>

int main(){
	int T;
	int tn = 1;
	scanf("%d",&T);
	long n,k,s;
	while(tn <= T){
		scanf("%ld %ld",&n,&k);
		int i;
		int flag0 = 0, flag1 = 0;
		int counter = 0;
		int inversions = 0;
		int string[n];
		for(i = 0;i < n;i ++){
			string[i] = getchar();
			if(flag0 = 1){
				if(string[i] == 1){
					flag0 = 0;
					flag1 = 1;
					counter = 1;
				}
				else{
					
					if(counter == k){
						string[i] = 1;
						flag1 = 1;
						flag0 = 0;
						inversions++;
						counter = 0; 
					}
					counter++;
				}
			}
			else if(flag1 == 1){
				if(string[i] = 0){
					flag0 = 1;
					flag1 = 0;
					counter = 1;
				}
				else{
					
					if(counter == k){
						string[i] = 0;
						flag0 = 1;
						flag1 = 0;
						inversions++;
						counter = 1; 
					}
					counter++;
				}
			}
			else{
				if(string[i] == 0){
					flag0 = 1;
					counter = 1;
				}
				else{
					flag1 = 1;
					counter = 1;
				}
			}
		}
		getchar();
		printf("\n%d\n",inversions );
		int index = 0;
		for(index = 0;index < n;index++){
			printf("%d",string[index]);
		}
		printf("\n");
		tn++;
	}
}