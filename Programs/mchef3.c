#include<stdio.h>
#include<stdlib.h>


typedef struct nodes{
	long long rating;
	long long costforremoval;

}node;

typedef struct judges{
	long long quote;
	long long left;
	long long right;
}judge;

long long ratings[100000 + 10]; //1 indexed
long long mincostforremoval[100000 + 10];
long long baddishes[100000 + 10];
node badarray[100000 + 10];
long long K[100000 + 10][510];
judge judges[100000 + 10];

long long max(long long a, long long b) { return (a > b)? a : b; }

long long knapSack(long long W, int n)	//val is the cost. long long W, int wt[], int val[], int n
{
   long long i, w;
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (badarray[i-1].costforremoval <= w)
                 K[i][w] = max(badarray[i-1].rating + K[i-1][w -badarray[i-1].costforremoval],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

static int cmpfunc (const void * a, const void * b)
{
    if( (*(judge *)a).quote - (*(judge *)b).quote < 0 )
        return -1;
    if( (*(judge *)a).quote - (*(judge *)b).quote > 0 )
        return 1;
    if( (*(judge *)a).quote - (*(judge *)b).quote == 0 )
        return 0;
}


int main(){
	long long T;
	long long N,M;
	int K;	//knapsack capacity
	
	scanf("%lld", &T);
	long long tn = 1;
	
	while(tn <= T){
		scanf("%lld %d %lld", &N, &K, &M);
		long long dishes = 1;
		long long rating;
		long long noofbaddishes = 0; //for baddishes array.
		long long ratingsum = 0;
		//		index = 1;	
		while(dishes <= N){
			scanf("%lld", &rating);
			ratingsum += rating;
			ratings[dishes] = rating;
			if(rating < 0){
				baddishes[noofbaddishes] = dishes;
				badarray[noofbaddishes].rating = rating * -1;
				noofbaddishes++;
			}
			mincostforremoval[dishes] = 550;		
			dishes++;
		}

		long long index;
		long long judgeno = 0;
		long long left;
		long long right;
		long long cost;

		while(judgeno < M){
			scanf("%lld %lld", &judges[judgeno].left, &judges[judgeno].right);
			scanf("%lld", &judges[judgeno].quote);
			judgeno++;
		}

		/*

			for(index = left; index <= right; index++){
				if(mincostforremoval[index] > cost)
					mincostforremoval[index] = cost;
			}
		*/
		qsort(judges,M,sizeof(judge),cmpfunc);
		
		long long index2;
		for(index = 1; index <= N; index++){
			for(index2 = 0; index2 < M; index2++){
				if(judges[index2].left <= index && judges[index2].right >= index){
					mincostforremoval[index] = judges[index2].quote;
					break;
				}
			}

		}

		badarray[0].costforremoval = 550;
		for(index = 0; index < noofbaddishes; index++){
			badarray[index].costforremoval = mincostforremoval[baddishes[index]];
		}

		long long removed;
		//knapsack(badarray[]);
		removed = knapSack(K, noofbaddishes);


		long long answer = ratingsum + removed;
		printf("%lld\n", answer);
		
		tn++;
	}


	return 0;
}