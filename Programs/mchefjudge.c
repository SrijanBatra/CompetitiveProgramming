#include<stdio.h>
#include<stdlib.h>

typedef struct j{
	long long left;
	long long right;
	long long cost;
}judge;

typedef struct dishes{
	long long rating;
	long long costing;
}dish;

int cmpfunct(const void* a, const void* b){
	long long val1 = (*((judge*)(a))).cost;

	long long val2 = (*((judge*)(b))).cost;
	if(val1 > val2){
		return 1;
	}
	if(val2 > val1){
		return -1;
	}
	else{
		return 0;
	}

}

long long ratings[100000 + 10];
dish baddishes[100000 + 10];
long long badindices[100000 + 10];
judge judges[100000 + 10];



long long max(long long a, long long b){
	if(a > b) return a;
	else return b;
}

long long K[100000 + 10][510];

long long knapsack(long long W, long long N){
	long long wt = 0;
	long long dishno = 0;
	long long i = 1;
	for(wt = 0; wt <= W; wt++){
		for(i = 1; i <= N; i++){
			if(i == 0 || wt == 0){
				K[i][wt] = 0;
			}
			else if(baddishes[dishno].costing < W){
				K[i][wt] = max(K[i-1][W - baddishes[i].costing] + baddishes[i].rating,K[i-1][wt]);
			}
	
			else
				K[i][wt] = 	K[i-1][wt];
		
		}	
	}
	
	return K[N][N];
}


int main(){
	long long T;
	scanf("%lld", &T);
	long long tn = 1;
	long long N, budget, M;
	while(tn <= T){
		long long sum = 0;
		scanf("%lld %lld %lld", &N, &budget, &M);
		long long index = 1;
		long long badindex = 1;
		for(index = 1; index <= N; index++){
			scanf("%lld", &ratings[index]);
			if(ratings[index] < 0){
				badindices[badindex] = index;
				baddishes[badindex].rating = -1 * ratings[index];
				baddishes[badindex].costing = 500;
				badindex++;
			}
			sum += ratings[index];			
		}
		
		for(index = 1; index <= M; index++){
			scanf("%lld %lld %lld", &(judges[index].left), &(judges[index].right) ,&(judges[index].cost));
		}
		
		qsort(judges, M, sizeof(judge), cmpfunct);
				
		for(index = 1; index < badindex; index++){
			long long pos;
			long long judgeno = 1;
			pos = badindices[index];
			while(judges[judgeno].left > pos || pos > judges[judgeno].right){
				judgeno++;
			}
			baddishes[index].costing = judges[judgeno].cost;			
		}
		
		long long removal;
		removal = knapsack(budget, badindex-1);
		long long answer = sum + removal;
		printf("%lld", answer);
		
		tn++;
	}

	return 0;
	
}
