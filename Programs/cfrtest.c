#include<stdio.h>
#include<stdlib.h>

int set[100];

static int cmpfunc (const void * a, const void * b)
{
    if( *(int *)a - *(int *)b < 0 )
        return -1;
    if( *(int *)a - *(int *)b > 0 )
        return 1;
    if( *(int *)a - *(int*)b == 0 )
        return 0;
}

int main(){
	int T;
	int tn = 0;
	scanf("%d",&T);
	int n;
	int index;
	int saves;
	int value;
	for(tn = 1; tn <= T; tn++){
		scanf("%d",&n);
		for(index = 0; index < n; index+=1){
			scanf("%d",&set[index]);
		}
		qsort(set,n,sizeof(int),cmpfunc);

		value = set[0];
		saves = 1;
		for(index = 1; index < n; index++){
			if(set[index] == value){
				continue;
			}
			else{
				saves ++;
				value = set[index];
			}

		}
		printf("%d\n", saves);
	}

	return 0;
}