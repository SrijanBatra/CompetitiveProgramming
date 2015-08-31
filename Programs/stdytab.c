#include<stdio.h>
#include<stdlib.h>


long long combs[2000 + 10];

long long CalCombinations(int m, long long combinations){
	int sum = 0;
	if(m == 1){
		return 1;
	}
	for(sum = 0; sum <= m; sum++){
		combinations = combinations * CalCombinations(m,combinations);
	}
}

int main(){
	int T;
	int tn = 1;
	
	while(tn <= T){
		scanf("%d %d", &n, &m);
		int n,m;
		int sum = 0;
		long long combinations;
		long long prevCombinations = 0;
		long long totalCombinations;
		combs[0] = 1;
		combs[1] = 1;
		for(sum = 0; sum <= m; sum++){
			combinations = CalCombinations(sum);
			totalCombinations = combinations * (combinations + prevCombinations);
			prevCombinations += combinations;
		}
		tn++;
	}

	return 0;
}