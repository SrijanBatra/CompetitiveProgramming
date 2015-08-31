#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long set[100000 + 10];
long long sum = 0;

int cmpfunc (const void *a, const void *b){
	return ( *(long long*)a - *(long long*)b);
}

void SumWithMod(long long add){
	sum = ((sum%(1000000000 + 7) + add%(1000000000 + 7))%(1000000000 + 7));
}

void printPowerSet(long long set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    long long counter, j;
 	long long min,max;
 	sum = 0;
    /*Run from counter 000..0 to 111..1*/
    for(counter = 1; counter < pow_set_size; counter++)
    {
    	
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j)){
            //printf("%lld ", set[j]);
            min = set[j];
            break;
           }
       }

       for(j = set_size-1; j >= 0; j--)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j)){
            //printf("%lld ", set[j]);
            max = set[j];
            break;
           }
       }
       SumWithMod(max-min);
       //printf("%lld %lld\n",max-min,sum );
       //printf("\n");
    }
}

int main(){
	//long long set[] = {1,2,3};
    sum = 0;
    //printPowerSet(set, 3);
 	//printf("%lld",sum);
    

    int T;
	scanf("%d",&T);
	int tn = 1;	
	long long n;
	//set[0] = 0;
	while(tn <= T){
		sum = 0;
		long long index;
		scanf("%lld",&n);
		for(index = 1; index < n; index++){
			scanf("%lld",&set[index]);
		}

		qsort(set,n,sizeof(long long),cmpfunc);
		/*
		for(index = 0; index < n - 1; index++){
			computeAll(index + 1,index,n);
		}
		*/
		//computeAll(1,1,n);
		printPowerSet(n);
		printf("%lld\n",sum);
		tn++;
	}
    return 0;
}