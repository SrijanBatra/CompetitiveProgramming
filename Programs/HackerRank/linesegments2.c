#include<stdio.h>
#include<stdlib.h>

typedef struct nodes{
	long long start;
	long long end;
}job;

static int cmpfunc (const void * a, const void * b)
{
    if( (*(job *)a).end - (*(job *)b).end < 0 )
        return -1;
    else if( (*(job *)a).end - (*(job *)b).end > 0 )
        return 1;
    else
        return 0;
}

long long findMax(job jobs[], long long n){
	if(n == 1)
		return 1;
	long long i = nonConflict();
	long long inclprof = 1;
	if(i != -1) 
		inclprof += findMax(jobs, i + 1);
	
}

int main(){
	long long N;
	scanf("%lld", &N);
	long long index;
	
	job jobs[100000 + 10];
	
	for(index = 0; index < N; index ++){
		scanf("%lld %lld", &jobs[index].start, &jobs[index].end);
	}
	
	qsort(jobs,N,sizeof(job),cmpfunc);
	long long dparray[100000 + 10];

	long long jobsSch;
	jobsSch = findMax(jobs, N);



	printf("%lld\n", jobsSch);
	return 0;
}