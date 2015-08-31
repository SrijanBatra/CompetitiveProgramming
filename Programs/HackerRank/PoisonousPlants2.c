#include<stdio.h>
#include<stdlib.h>



typedef struct nodes{
	long long value;
	long long position;
}node;

node P[100000 + 10];

static int cmpfunc (const void * a, const void * b)
{
    if( (*(node *)a).value - (*(node *)b).value < 0 )
        return -1;
    if( (*(node *)a).value - (*(node *)b).value > 0 )
        return 1;
    if( (*(node *)a).value - (*(node *)b).value == 0 )
        return 0;
}

int main(){
	long long N;
	scanf("%lld", &N);
	long long index = 0;
	while(index < N){
		scanf("%lld", &P[index]->value);
		P[index]->position = index;
		index++;
	}
	
	qsort(P,N,sizeof(node),cmpfunc);
	


}