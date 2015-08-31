#include<stdio.h>
#include<stdlib.h>

 

typedef struct nodes{
    long long start;
    long long end;
}Job;

 

long long latestNonConflict(Job arr[], int i)
{
    int j;
    for (j=i-1; j>=0; j--)
    {
        if (arr[j].end < arr[i].end && arr[j].start < arr[i].start)
            return j;
    }
    return -1;
}
 

static int cmpfunc (const void * a, const void * b)
{
    if( (*(Job *)a).end - (*(Job *)b).end < 0 )
        return -1;
    else if( (*(Job *)a).end - (*(Job *)b).end > 0 )
        return 1;
    else
        return 0;
}



long long findMaxProfit(Job Jobs[], long long n)
{
    // Sort Jobs according to finish time
    
    qsort(Jobs,n,sizeof(Job),cmpfunc);

    long long table[100000 + 10];
    table[0] = 1;


    
    int i;

    for (i=1; i < n; i++)
    {
        
        int inclProf = 1;
        int l = latestNonConflict(Jobs, i);
        if (l != -1)
            inclProf += table[l];
 
        
        if(inclProf > table[i-1])
            table[i] = inclProf;
        else
            table[i] = table[i-1];
    }
 
    
    long long result = table[n-1];
 
    return result;
}
 

int main()
{
    long long N;
    scanf("%lld", &N);
    long long index;
    
    Job Jobs[100000 + 10];
    
    for(index = 0; index < N; index ++){
        scanf("%lld %lld", &Jobs[index].start, &Jobs[index].end);
    }

    long long JobsSch;
    JobsSch =  findMaxProfit(Jobs, N);

    printf("%lld\n", JobsSch);
    return 0;
}