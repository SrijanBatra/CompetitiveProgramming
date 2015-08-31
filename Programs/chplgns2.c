	#include<stdio.h>
#include<stdlib.h>

typedef struct nodes{
	long long key;
	long long value;
}node;


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
	long long T;
	scanf("%lld",&T);
	long long tn = 1;	
	long long n;
	long long minx[100000 + 10];
	long long index = 0;
	long long j = 0;
	while(tn <= T){
		scanf("%lld", &n);
		long long answer[100000 + 10];
		node vertices[100000 + 10];
		for(index = 0; index < n; index++){
			//vertices[index] = (node*)malloc(sizeof(node));
			vertices[index].key = index;
			answer[index] = 0;
			long long v;
			scanf("%lld", &v);			
			long long x;
			long long y;
			long long tminx;
			scanf("%lld %lld", &x, &y);
			tminx = x;
			for(j = 1;j < v; j++){
				scanf("%lld %lld", &x, &y);
				if(x < tminx) tminx = x;
			}
			minx[index] = tminx;
			vertices[index].value = tminx;
		}

		/*
		for(index = 0; index < n; index++){
			for(j = index + 1;j < n; j++){
				if(minx[index] < minx[j]) answer[index]++;
				else answer[j]++;
			}
		}
		*/
		qsort(vertices,n,sizeof(node),cmpfunc);
		
		for(index = 0; index < n; index++){
			answer[vertices[index].key] = n - index - 1;
		}

		for(index = 0; index < n; index++){
			printf("%lld ", answer[index]);
		}
		printf("\n");
		tn++;
	}


	return 0;
}