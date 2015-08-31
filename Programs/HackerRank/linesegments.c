#include<stdio.h>
#include<stdlib.h>

typedef struct nodes{
	long long start;
	long long end;
}job;

static int cmpfunc (const void * a, const void * b)
{
    if( (*(job *)a).start - (*(job *)b).start < 0 )
        return -1;
    else if( (*(job *)a).start - (*(job *)b).start > 0 )
        return 1;
    else
        return 0;
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

	long long lastFinish = jobs[N-1].end;
	long long lastStart = jobs[N-1].start;
	long long lastSchStart = lastStart;
	long long lastSchFinish = 0;
	index = N - 2;
	while(jobs[index].start == lastStart){
		if (jobs[index].end > lastFinish){
			lastFinish = jobs[index].end;
		}

		index--;
	}
	lastSchFinish = lastFinish;
	long long jobsSch = 1;
	
	while(index >= 0){

		if(jobs[index].end < lastSchFinish){
			lastStart = jobs[index].start;
			lastSchStart = lastStart;
			lastFinish = jobs[index].end;
			index--;

			while(jobs[index].start == lastSchStart){
				if (jobs[index].end > lastFinish && jobs[index].end < lastSchFinish){
					lastFinish = jobs[index].end;
				}
				index--;
			}
			lastSchFinish = lastFinish;
			jobsSch++;
		}
		
		
		
		else
			index--;
	}

	printf("%lld\n", jobsSch);
	return 0;
}